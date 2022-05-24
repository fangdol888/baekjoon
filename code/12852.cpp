#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

int n;
vector<int> res;
vector<int> before;

int solve(){
    res[1] = 0;
    before[1] = -1;

    for(int i=2;i<=n;i++){
        res[i] = res[i-1] + 1;
        before[i] = i - 1;

        if( i%2==0 && res[i] > res[i/2] + 1){
            res[i] = res[i/2] + 1;
            before[i] = i / 2;
        }
        if( i%3==0 && res[i] > res[i/3] + 1){
            res[i] = res[i/3] + 1;
            before[i] = i / 3;
        }
    }

    return res[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    res.resize(n+1);
    before.resize(n+1);
    
    solve();
    cout << res[n] << '\n';

    while(n!=-1){
        cout << n << ' ';
        n = before[n];
    }
    return 0;
}