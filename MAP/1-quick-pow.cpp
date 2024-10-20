#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MOD = 100000;

int qpow(int a, int n){
    if(n == 0){
        return 1;
    }
    int ncase = (n % 2 == 1) ? a : 1;
    int x = qpow(a, n/2);
    int y = (long long) x * x % MOD;
    return (long long) y * ncase % MOD;
}

int main(){
    int a, n;
    cin >> a >> n;
    cout << qpow(a, n);
    return 0;
}
