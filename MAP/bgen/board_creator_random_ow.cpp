#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(){
    srand (time(NULL));
    int H = rand() % 1001;
    int W = rand() % 1001;
    cout << H << " " <<  W << "\n";
    for(int i=0; i < H; i++){
        for(int j=0; j<W; j++){
            cout << ((rand() % 2 == 1) ? 'x' : '-');
        }
        cout << "\n";
    }
}
