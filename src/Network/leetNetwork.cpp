#include <vector>
#include <iostream>
using namespace std;

typedef struct node {
    int point;
    bool used;
    node* next;
} node;

class Solution {
public:
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
                    // network[computer->point]->used = true;
                    // node *vizinho = computer->next;
                    // while (vizinho != NULL){
                    //     if (network[vizinho->point]->used == false){
                    //         S.push_back(vizinho->point);
                    //         network[vizinho->point]->used = true;
                    //     }
                    //     vizinho = vizinho->next;                    
                    // }
                    // computer = network[computer->point];
                }
                computer = computer->next;       
            } 
        }
        
        return;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
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
                    cout << "oi" << endl;
                    break;
                } else exit = true;
            }
        }
        return unconnected;
    }
};