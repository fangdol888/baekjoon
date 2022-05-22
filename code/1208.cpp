#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
int n,s;
long long ans=0;
vector<int> input;
map<int, int> mp;
int half;

void dfsLeft(int idx, int sum){
    if(idx == half){
        mp[sum]++;
        return;
    }else{
        dfsLeft(idx+1, sum);
        dfsLeft(idx+1, sum + input[idx]);
    }
}

void dfsRight(int idx, int sum){
    if(idx == n){
        ans += mp[s - sum];
        return;
    }else{
        dfsRight(idx+1, sum);
        dfsRight(idx+1, sum + input[idx]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;

    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        input.push_back(tmp);
    }
    half = n/2;
    dfsLeft(0,0);
    dfsRight(half,0);
    if(s==0) ans--;
    cout << ans <<'\n';
    return 0;
}