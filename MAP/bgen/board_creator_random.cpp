#include <iostream>
#include <random>
#include <time.h>
using namespace std;

bool has_start, has_end = false;

char set_flag(char a){
    if(a == 'o'){
        has_start = true;
    }else if(a == 'w'){
        has_end = true;
    }
    return a;
}

int main(){
    srand (time(NULL));
    int H = rand() % 1001;
    int W = rand() % 1001;
    cout << H << " " <<  W << "\n";
    for(int i=0; i < H; i++){
        for(int j=0; j<W; j++){
            cout << ((rand() % 2 == 1) ? 'x' : ((rand() % 2 == 1 && !has_start) ? set_flag('o') : ((rand() % 2 == 1 && !has_end) ? set_flag('w') : '-' )));
        }
        cout << "\n";
    }
}
