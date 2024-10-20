#include <iostream>
#include <vector>
using namespace std;
    
int H, W;
string r[1000];
bool visited[1000][1000];
bool found_exit = false;
pair<int, int> directions[4] = {
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};


pair<int, int> start_pos;
pair<int, int> end_pos;

bool in_bounds(int row, int col){
    return row >= 0 && row < H && col >= 0 && col < W;
}

void dfs(int row, int col){
    if(found_exit) return;
    visited[row][col] = true;

    if(row == end_pos.first && col == end_pos.second){
        found_exit = true;
        return;
    }
    for(int i=0; i<4; i++){
        int r2 = row + directions[i].first;
        int c2 = col + directions[i].second;
        if(in_bounds(r2, c2) && !visited[r2][c2] && r[r2][c2] != 'x'){
            dfs(r2, c2);
        }
    }
}

int main(){
    cin >> W >> H;
    for(int i=0; i<H; i++){
        cin >> r[i];
        for(int j=0; j<W; j++){
            if(r[i][j] == 'o'){
                start_pos = {i, j};
            }else 
            if(r[i][j] == 'w'){
                end_pos = {i, j};
            }
        }
    }

    dfs(start_pos.first, start_pos.second);

    if(visited[ end_pos.first ][ end_pos.second ]){
        cout << "TAK";
    }else{
        cout << "NIE";
    }
}
