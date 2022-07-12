#include <iostream>
#include <queue>
using namespace std;
//DSLR

int t;
bool visit[10001];

void bfs(int a , int b){
    queue<pair<int,string>> q;
    q.push({a,""});

    for(auto& a : visit){
        a = false;
    }

    while(!q.empty()){
        auto cur = q.front(); q.pop();
        
        if(cur.first == b){
            cout << cur.second << '\n';
            return;
        }

        //d
        int d = (cur.first * 2) % 10000;
        if(!visit[d]){
            visit[d] = true;
            q.push( {d, cur.second +"D" });
        }
        

        //s
        int s = (cur.first -1 + 10000) % 10000;
        if(!visit[s]){
            visit[s] = true;
            q.push( {s, cur.second +"S" });
        }
        //l
   
        int l = (cur.first * 10 + (cur.first / 1000)) % 10000;
        if(!visit[l]){
            visit[l] = true;
            q.push( {l, cur.second +"L" });
        }
        
        
        //r
       
        int r = (cur.first%10)*1000 + cur.first/10 ;
        if(!visit[r]){
            visit[r] = true;
            q.push({r, cur.second +"R" });
        }
        
    }
    
}

int main(){
    cin >> t;
    for(int test=0;test<t;test++){
        int a, b;
        cin >> a >> b;
        bfs(a,b);

    }
    return 0;
}