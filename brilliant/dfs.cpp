#include <iostream>
#include <stdcpp.h>
using namespace std;

const int n = 1000;
vector<int> neighbours[n];
bool visited[n];
string states[81];

bool follows_eating_rule(int b){
    //states[b] = 
    return true;
}

bool follows_boat_rule(int b){
    return true;
}

bool is_okay(int b){
    return follows_eating_rule(b) && follows_boat_rule(b);
}

string decimal_to_base(int base, int n){
    string res = "";
    //cout << res << ";" << n << "\n";
    if(n == 0){
        return "0000";
    }
    while(n != 0){
        //cout << res << "\n";
        res = to_string(n%base) + res;
        n = n/base;
    }
    for(int i=res.size(); i<4; i++){
        res = "0" + res;
    }
    //cout << res << "\n\n";
    return res;
}

void dfs(int a){
    cout << states[a] << " ";
    visited[a] = true;
    if(a == 80){
        return;
    }
    for(int b : neighbours[a]){
        if(!visited[b] && !is_okay(b)){
            dfs(b);
        }
    }
}

void link(int a, int b){
    neighbours[a].push_back(b);
    neighbours[b].push_back(a);
}
int main(){
    for(int i=0; i<81; i++){
        states[i] = decimal_to_base(3, i);
        cout << states[i] << "\n";
    }
    for(int i=0; i<81; i++){
        if(states[i][0] == "1"){
            string moves = states[i];
            moves[0] = "0";
            link((  ), base3_to_decimal);
            string moves = states[i];
            moves[1] = "2";
            link((  ), base3_to_decimal);
        }else{
            string moves = "1" + states[i].substr(1,3);
            moves[1] = "1";
            link((  ), base3_to_decimal);
            string moves = "1" + states[i].substr(1,3);
            moves[2] = "1";
            link((  ), base3_to_decimal);
            string moves = "1" + states[i].substr(1,3);
            moves[3] = "1";
            link((  ), base3_to_decimal);
        }
    }
    link(0, 1);
    link(0, 3);
    link(1, 4);
    link(1, 2);
    link(4, 6);
    link(3, 2);
    link(5, 7);

    dfs(0);
}
