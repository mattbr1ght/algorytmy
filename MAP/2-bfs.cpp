#include <iostream>
#include <vector>
using namespace std;
    
vector<int> neighbours[8];
bool visited[8];
int dist[8];

void bfs(int a){
    
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
    int n = 8;

    //BFS
    vector<int> v;
    v.push_back(0);
    dist[0] = 0;
    visited[0] = 0;

    for(int i=0; i< (int) v.size(); i++) {
        int a = v[i];
        for(int b: neighbours[a]) {
            if (!visited[b]){
                visited[b]= true;
                dist[b] = dist[a] + 1;
                v.push_back(b);
            }
        }
    }
    

    for(int i = 0; i<n; i++){
        cout << i << ": " << dist[i] << "\n";
    }
}
