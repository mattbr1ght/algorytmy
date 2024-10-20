//budowanie lotniska
//[bud](https://szkopul.edu.pl/problemset/problem/E0WdV0P4l3hYG2WAuFWyQ-TV/site/?key=statement)
#include <iostream>
#include <vector>
using namespace std;
    
int n, m;
//bool visited[1500][1500];
int max_dist[1500][1500];
pair<int, int> directions[4] = {
    {1, 0}, //right
    {0, 1}, //down
    {-1, 0}, //left
    {0, -1} //up
};
string r[1500];

bool in_bounds(int x, int y){
    return x >= 0 && x < n && y >= 0 && y < n;
}

int max_length_from_point(int row, int col){
    if(r[row][col] == 'X'){
        max_dist[row][col] = 0;
        return 0;
    }
    int max = 1;
    for(int i=0; i<4; i++){
        int lmax = 1;
        int r2 = row + directions[i].first;
        int c2 = col + directions[i].second;
        //cout << row << ";" << col << " : " <<  << "\n";
        while(in_bounds(r2, c2) && r[r2][c2] != 'X'){
            max = (max<++lmax) ? lmax : max;
            r2 += directions[i].first;
            c2 += directions[i].second;
            //cout << "in while : " << r2 << ";" << c2 << "\n"; 
        }
    }
    max_dist[row][col] = max;
    return max; 
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i < n ; i++){
        cin >> r[i];
    }
    int max = 0;
    for(int r=0; r<n; r++){
        for(int c=0; c<n; c++){
            int lmax = max_length_from_point(r, c);
            max = (lmax > max) ? lmax : max;
        }
    }
    cout << max << "\n\n";
    
    for(int r = 0; r<n; r++){
        for(int c = 0; c<n; c++){
            if(max_dist[r][c] == 0 ) {
                cout << "X";
            }else{
                cout << max_dist[r][c];
            }
        }
        cout << "\n";
    }
}
