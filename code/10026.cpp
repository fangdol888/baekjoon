#include <iostream>
#include <queue>
using namespace std;
char map[101][101];
bool visit[101][101];
int dx[4] ={0,1,0,-1};
int dy[4] = {1,0,-1,0};

int n;

void non_gr(char ch, int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    visit[y][x] = true;

    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int lx = cur.first + dx[dir];
            int ly = cur.second + dy[dir];
            if(lx <0 || ly <0 || lx>n || ly>n|| visit[ly][lx]) continue;
            if(map[ly][lx] != ch) continue;
            visit[ly][lx] = true;
            q.push({lx,ly});
        }  
    }
}

void gr(char ch, int x, int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    while(!q.empty()){
        auto cur = q.front();q.pop();
        for(int dir=0;dir<4;dir++){
            int lx = cur.first + dx[dir];
            int ly = cur.second + dy[dir];
            if(lx <0 || ly <0 || lx>n || ly>n || visit[ly][lx]) continue;
            if(ch == 'R' || ch=='G')
            {
                if(map[ly][lx] == 'R' || map[ly][lx] =='G'){
                    visit[ly][lx] = true;
                    q.push({lx,ly});
                }
            }else{
                if(map[ly][lx] != ch) continue;
                visit[ly][lx] = true;
                q.push({lx,ly});
            }
        }  
    }
}

int main(){
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }
    int sum[2] ={0,0};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                non_gr(map[i][j], j, i);
                sum[0]++;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            visit[i][j] = false;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visit[i][j]){
                gr(map[i][j], j, i);
                sum[1]++;
            }
        }
    }

    cout << sum[0] << ' '<<sum[1] << '\n';
    return 0;
}