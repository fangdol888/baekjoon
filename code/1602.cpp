#include <iostream>
#include <vector>
using namespace std;

int n, m, q;
vector<vector<int>> route;
vector<int> bother;
int main(){
    cin >> n >> m >> q;
    route.resize(n);
    for(int i=0;i<n;i++){
        route[i].resize(n);
        route[i].assign(n,-1);
        route[i][i] = 0;
    }
    bother.resize(n);
    for(int i=0;i<n;i++){
        cin >> bother[i];    
    }
    for(int i=0;i<m;i++){
        int s,t,w;
        cin>> s >> t >> w;
        route[s][t] = route[t][s] = w;
        
    }
    return 0;
}