#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
vector<int> edge[1002];
int num[1002];

int main(){
    cin >> n >> m;

    for(int i=0;i<m;i++){
        int t;
        cin >> t;
        int st=0,en=0;

        cin >> st;
        for(int j =1; j<t;j++){
            cin >> en;
            edge[st].push_back(en);
            num[en]++;
            st = en;
        }
    }


    queue<int> q;

    for(int i =1;i<=n;i++){
        if(num[i] == 0){
            q.push(i);
        }
    }
    vector<int> v;

    while(!q.empty()){
        auto cur = q.front();q.pop();
        v.push_back(cur);

        for(auto next : edge[cur]){
            if(--num[next]==0){
                q.push(next);
            }
        }
              
    }

    if(v.size() != n)
    {
        cout << 0 << '\n';

    }else{
        for(auto e : v){
            cout << e << '\n';
        }
    }
    return 0;
}
