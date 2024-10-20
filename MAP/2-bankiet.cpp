#include <iostream>
#include <vector>
using namespace std;
    
vector<int> neighbours[30000];
bool visited[30000];

void dfs(int a){
    visited[a] = true;
    for(int b : neighbours[a]){
        if(!visited[b]){
            dfs(b);
        }
    }
}

void f(int a, int b){
    neighbours[a].push_back(b);
    neighbours[b].push_back(a);
}
int main(){

    int n;
    cin >> n;

    for(int i=0; i < n; i++){
        int tmp;
        cin >> tmp;
        f(i, tmp-1);
    }

    int count = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            count+=1;
        }
    }
    cout << count;
}
