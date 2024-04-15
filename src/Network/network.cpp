#include <vector>
#include <iostream>
using namespace std;

typedef struct node {
    int point;
    node* next;
} node;

int main(){
    int n = 4;    
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    vector<node*> network (n, NULL);
    int unconected = 0;

    for (int i = 0; i < connections.size(); i++){
        node *new1 = (node*)malloc(sizeof(node));
        new1->point = connections[i][1];
        new1->next = network[connections[i][0]];
        network[connections[i][0]] = new1;

        node *new2 = (node*)malloc(sizeof(node));
        new2->point = connections[i][0];
        new2->next = network[connections[i][1]];
        network[connections[i][1]] = new2;   
    }

    for (int i = 0; i < network.size(); i++){
        if (network[i] == NULL) unconected++;
    }
    // cout << endl << network[1]->point << endl;
    // cout << unconected << endl;
    int teste = connections.size();
    if (n - teste > 0) cout << unconected << endl;
    else cout << -1;
    return 0;
}