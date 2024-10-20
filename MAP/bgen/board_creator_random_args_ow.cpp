#include <iostream>
#include <random>
#include <time.h>
using namespace std;

int main(int argc, char* argv[]){
    srand (time(NULL));
    int H = atoi(argv[1]);
    int W = atoi(argv[2]);
    cout << H << " " <<  W << "\n";
    for(int i=0; i < H; i++){
        for(int j=0; j<W; j++){
            cout << ((rand() % 2 == 1) ? 'x' : '-');
        }
        cout << "\n";
    }
}
