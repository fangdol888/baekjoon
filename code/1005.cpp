#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, k;
int w;

struct Buildup{
    int cost;
    int path;

};
vector<int> pre_build;
vector<int> next_build;
vector<int> indegree;
vector<Buildup> buildup;

void bfs(int w){
    queue<int> q;
    for(int i=1;i<buildup.size();i++){
        if(indegree[i] == 0){ //pre 비어 있다면
            q.push(i); //초기 건물 넣기
        }
    }
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(int pre = 1; pre <= k; pre++){
            if(pre_build[pre] == cur){
                int next = next_build[pre];            
                if( buildup[next].path < buildup[cur].path + buildup[cur].cost){ //더 시간이 걸리는 빌드가 있다면
                    buildup[next].path = buildup[cur].path + buildup[cur].cost;
                }
                if(--indegree[next] == 0){
                    q.push(next);
                }

            }
        }
       
    }
    cout << buildup[w].path + buildup[w].cost << '\n';
}

int tc;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;

    for(int t=0;t<tc;t++){
        
        cin >> n >> k;

        pre_build.clear();
        next_build.clear();
        indegree.clear();
        buildup.clear();

        pre_build.resize(k+1);
        next_build.resize(k+1);
        indegree.resize(n+1);
        buildup.resize(n+1);

        for(int i=1;i<=n;i++){
            cin >> buildup[i].cost;
            buildup[i].path = 0;
        }
        for(int i=1;i<=k;i++){
            int pre, next;
            cin >> pre_build[i] >> next_build[i];
            indegree[next_build[i]]++;
        }

        cin >> w;
        
        bfs(w);
    }
    return 0;
}