#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define pii pair<int,int>
using namespace std;
int n,k;
vector<pii> jew;
priority_queue<int> pq; //보석
vector<int> inven;

bool compare(pii a, pii b){ // 가치 있는 순서대로
    if(a.second == b.second) return a.first < b.first;
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    jew.resize(n);
    inven.resize(k);

    for(int i=0;i<n;i++){
        cin >> jew[i].first >> jew[i].second;
    }
    for(int i=0;i<k;i++){
        cin >> inven[i];
    }
    sort(inven.begin(), inven.end());
    sort(jew.begin(), jew.end());
    
    int idx = 0;
    long long result = 0;

    for(auto c : inven){
        while(idx < n && c >= jew[idx].first){ //가장 작은 가방에 들어갈 정도면 그 뒷 가방도 다 가능
            pq.push(jew[idx++].second);
        }

        if(!pq.empty()){ // 가능 한 것 중에서 가장 가치가 큰 것부터
            result += pq.top(); pq.pop();
        }
    }
    cout << result << '\n'; 
    return 0;
}