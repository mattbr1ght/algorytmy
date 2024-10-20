#include <iostream>
#include <vector>
using namespace std;

const int MAX = 200000; 

vector<int> edges[MAX];
int parent[MAX];
int subsize[MAX];

void dfs(int a){
    for(int b: edges[a]){
        if(parent[a] == b){
            continue;
        }
        dfs(b);
        subsize[a] += subsize[b];
    }
    subsize[a]++;
}

int main(){
    int n;
    cin >> n;
    for(int i = 1; i<n; i++){
       cin >> parent[i];
       parent[i]--;
       edges[parent[i]].push_back(i);
       edges[i].push_back(parent[i]);
    }
    
    dfs(0);

    for(int i=0; i<n; i++){
        cout << subsize[i]-1 << " ";
    }

    return 0;
}
