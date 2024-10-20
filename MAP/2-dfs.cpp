#include <iostream>
#include <vector>
using namespace std;
    
vector<int> neighbours[8];
bool visited[8];

void dfs(int a){
    cout << a << " ";
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
    f(0, 1);
    f(0, 3);
    f(1, 4);
    f(1, 2);
    f(4, 6);
    f(3, 2);
    f(5, 7);

    for(int i = 0; i<8; i++){
        if(!visited[i]){
            cout << "Początek spójnej ";
            dfs(i);
            cout << "\n";
        }
    }
}
