#include <iostream>
#include <vector>
using namespace std;

typedef struct couple{
    int n1;
    int n2;
    int prox1;
    int prox2;
} couple;

int main(){
    vector<int> row = {0,2,3,1};
    vector<couple*> couples;
    for (int i = 0; i < row.size(); i+=2){
        couple *node = (couple*)malloc(sizeof(couple));
        if (row[i]%2 == 0)
            node->n1 = row[i]/2;
        else node->n1 = (row[i])/2; 
        cout << node->n1 << endl;
        if (row[i+1]%2 == 0)
            node->n2 = row[i+1]/2;
        else node->n2 = (row[i+1])/2; 
        cout << node->n2 << endl;
        node->prox1 = -1;
        node->prox2 = -1;       
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

    cout << endl << couples[couples[1]->prox1]->n1 << endl;
    return 0;
}