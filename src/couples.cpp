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
    vector<int> row = {0,4,1,5,8,6,7,2,3,9};
    vector<couple*> couples;
    for (int i = 0; i < row.size(); i++)
        cout << row[i] << endl;
    return 0;
}