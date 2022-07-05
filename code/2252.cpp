#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<vector<int>> comp;
vector<bool> visit;
vector<int> income;

int main(){
    cin >> n >> m;
    comp.resize(n+1);
    income.resize(n+1);
    visit.resize(n+1);

    for(int i=0;i<m;i++){
        int tall, small;
        cin >> tall >> small;
        comp[tall].push_back(small);
        income[small]++;
    }
    queue<int> inc0;

    for(int i=1;i<=n;i++){
        if(income[i] == 0) inc0.push(i);
    }

    while(!inc0.empty()){
        auto cur = inc0.front(); inc0.pop();
        cout << cur << ' ';

        for(auto chi: comp[cur]){
            if(--income[chi] == 0){
                inc0.push(chi);
            }
        }
    }
    cout << '\n';
    return 0;
}