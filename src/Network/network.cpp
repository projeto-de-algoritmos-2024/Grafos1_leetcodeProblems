#include <vector>
#include <iostream>
using namespace std;

typedef struct node {
    int point;
    bool used;
    node* next;
} node;

vector<int> S;
int unconnected = -1;
int BFS (vector<node*> network){
    int counter = 0;
    for (int i = 0; i < network.size(); i++){
        if (network[i] != NULL){
            if (network[i]->used == false){
                network[i]->used = true;
                S.push_back(i);
                unconnected++;           
                break;
            } 
        } else unconnected++;             
    }
    if (S.empty()) return 0;

    while (S.empty() == false){
        int u = S.front();
        S.erase(S.begin());
        node *computer = network[u];
        vector<int> vizinho;   

        while (computer != NULL){
            vizinho.push_back(computer->point);
            computer = computer->next;
        }

        for (int i = 0; i < vizinho.size(); i++){
            if (network[vizinho[i]]->used == false){
                network[vizinho[i]]->used = true;
                counter++;
                S.push_back(vizinho[i]);
            }
        }
    }
    return counter + BFS(network);
}

int main(){
    int n = 4;    
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    vector<node*> network (n, NULL);

    for (int i = 0; i < connections.size(); i++){
        node *new1 = (node*)malloc(sizeof(node));
        new1->point = connections[i][1];
        new1->used = false;
        new1->next = network[connections[i][0]];        
        network[connections[i][0]] = new1;

        node *new2 = (node*)malloc(sizeof(node));
        new2->point = connections[i][0];
        new2->used = false;
        new2->next = network[connections[i][1]];        
        network[connections[i][1]] = new2;   
    }
    int cabosUsados = BFS(network);
    int cabosRestantes = connections.size() - cabosUsados;
    cout << cabosUsados << " : " << unconnected << endl;
    cout << cabosRestantes << endl;

    return 0;
}