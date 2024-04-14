#include <iostream>
#include <vector>
using namespace std;

typedef struct couple{
    int n1;
    int n2;
    bool used;
    int prox1;
    int prox2;
} couple;

vector<int> S;
int BFS (vector<couple*> couples){
    int counter = 0;
    for (int i = 0; i < couples.size(); i++){
        if (couples[i]->used == false){
            couples[i]->used = true;
            S.push_back(i);            
            break;
        }        
    }
    if (S.empty()) return 0;
    while (S.empty() == false){
        int u = S.front();
        S.erase(S.begin());
        int vizinho1 = couples[u]->prox1;
        int vizinho2 = couples[u]->prox2;
        if (couples[vizinho1]->used == false){
            couples[vizinho1]->used = true;
            counter++;
            S.push_back(vizinho1);
        }
        if (couples[vizinho2]->used == false){
            couples[vizinho2]->used = true;
            counter++;
            S.push_back(vizinho2);
        }
    }
    return counter + BFS(couples);
}

int main(){
    vector<int> row = {0,4,1,5,8,6,7,2,3,9};
    vector<couple*> couples;
    for (int i = 0; i < row.size(); i+=2){
        couple *node = (couple*)malloc(sizeof(couple));
        if (row[i]%2 == 0)
            node->n1 = row[i]/2;
        else node->n1 = (row[i])/2; 
        if (row[i+1]%2 == 0)
            node->n2 = row[i+1]/2;
        else node->n2 = (row[i+1])/2; 
        node->prox1 = -1;
        node->prox2 = -1;   
        node->used = false;    
        couples.push_back(node);
    }
    
    for (int i = 0; i < couples.size(); i++){
        couple*node = couples[i];
        if (node->n1 == node->n2){
            node->prox1 = node->prox2 = i;
        }
        else if(node->prox1 == -1 || node->prox2 == -1) {
            for (int j = i+1; j < couples.size(); j++){
                if (couples[j]->n1 == node->n1){
                    couples[j]->prox1 = i;
                    node->prox1 = j;
                } else if (couples[j]->n2 == node->n1){
                    couples[j]->prox2 = i;
                    node->prox1 = j;
                }
                if (couples[j]->n1 == node->n2){
                    couples[j]->prox1 = i;
                    node->prox2 = j;
                } else if (couples[j]->n2 == node->n2){
                    couples[j]->prox2 = i;
                    node->prox2 = j;
                }
            }
        }
    }

    cout << BFS(couples) << endl;
    return 0;
}