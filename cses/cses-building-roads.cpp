#include <iostream>
#include <vector>
using namespace std;
    
vector<int> neighbours[200000];
bool visited[2000000];
vector<int> components;
void dfs(int a){
    //cout << a << " ";
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

    int n, m;
    cin >> n >> m;
    for(int i = 0; i<m; i++){
        int a, b;
        cin >> a >> b;
        f(a-1,b-1);
    }

    int count = 0;
    for(int i = 0; i<n; i++){
        if(!visited[i]){
            dfs(i);
            count += 1;
            if(i != 0){
                components.push_back(0);
                components.push_back(i);
            }
        }
    }
    cout << count - 1 << "\n";
    for(int i=0; i<components.size(); i++){
        cout << components[i] + 1 <<  " " << components[++i] + 1 << "\n";
    }
    
}
