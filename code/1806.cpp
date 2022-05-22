#include <iostream>
#include <vector>
#define MAX 10000000
using namespace std;
int n, s;
int f=0, e=0;
int len=MAX;
int sum=0;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<int> in;
    cin >> n >> s;
    in.resize(n);

    for(int i=0;i<n;i++){
        cin >> in[i];
    }

    while(f <= e){
        if(sum >= s){ //부분합이 더 크면
            len = min(len, e- f);
            sum -= in[f++];
            
        }else if (e == n) break;
        else{ 
            sum += in[e++];
        }
    }

    if(len >= n+1) cout << 0 << '\n';
    else cout << len << '\n';
    return 0;
}