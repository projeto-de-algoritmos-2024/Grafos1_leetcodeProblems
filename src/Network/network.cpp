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
    if (network[3] == NULL) cout << "Taquei o piru na portuquesa" << endl;
    for (int i = 0; i < connections.size(); i++){

        node *new1 = (node*)malloc(sizeof(node));
        new1->point = connections[i][1];
        new1->next = network[connections[i][0]];
        network[connections[i][0]] = new1;
        node *new2 = (node*)malloc(sizeof(node));
        new2->point = connections[i][0];
        new2->next = network[connections[i][1]];   
    }
    return 0;
}