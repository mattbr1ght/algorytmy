#include <iostream>
#include <vector>
using namespace std;const int M=200000;vector<int> e[M];int d[M];int z=0;void f(int a,int g,int p){for(int b:e[a]){if(b!=p){f(b,g+1,a);}}z=(d[z]<g)?a:z;d[a]=g;}int main(){int n;cin>>n;for(int i=0;i<n-1;i++){int a,b;cin>>a>>b;e[a-1].push_back(b-1);e[b-1].push_back(a-1);}f(0,0,0);for(int i=0;i<M;i++){d[i]=0;}f(z,0,-1);cout<<d[z];}
