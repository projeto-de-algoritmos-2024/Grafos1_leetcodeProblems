#include <vector>
#include <iostream>
using namespace std;

typedef struct node {
    int point;
    bool used;
    node* next;
} node;

int unconnected = -1;
vector<int>S;
void DFS (vector<node*> network, int visited){     
    S.push_back(visited);   
    while (S.empty() == false){ 
        visited = S.back();
        S.pop_back();
        network[visited]->used = true;
        node *computer = network[visited];
        while (computer != NULL){
            if (network[computer->point]->used == false){
                S.push_back(computer->point);
            }
            computer = computer->next;       
        } 
    }
    
    return;
}

int main(){
    int n = 5;    
    vector<vector<int>> connections = {
        {0,1},{0,2},{3,4},{2,3}
    };
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
    for (int i = 0; i < network.size(); i++){
        if (network[i] == NULL){
            node* fill = (node*)malloc(sizeof(node));
            fill->used = true;
            network[i] = fill;
            unconnected++;
        }
    }
    bool exit = false;
    while (exit == false){
        for (int i = 0; i < network.size(); i++){
            if (network[i]->used == false){
                exit = false;
                DFS (network, i);
                unconnected++;
                break;
            } else exit = true;
        }
    }

    cout << "Resposta:" << endl;
    cout << unconnected << endl;

    return 0;
}