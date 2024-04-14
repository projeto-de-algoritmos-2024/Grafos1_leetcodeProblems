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
    vector<int> row = {0,2,3,4};
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
    }
    return 0;
}