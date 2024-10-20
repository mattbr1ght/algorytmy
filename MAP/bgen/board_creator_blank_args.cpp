#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    int H = atoi(argv[1]);
    int W = atoi(argv[2]);
    cout << H << " " <<  W << "\n";
    for(int i=0; i < H; i++){
        for(int j=0; j<W; j++){
            cout << "-";
        }
        cout << "\n";
    }
}
