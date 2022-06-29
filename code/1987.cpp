#include <iostream>
#include <queue>
using namespace std;

char map[20][20];
bool alpha[28];

int r,c;
int sum = 1;
int mx = 0;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


void dfs(int x, int y){
    if(x<0||y<0||x>=c||y>=r||alpha[map[y][x] - 'A']){
        return;
    }
    else{
        alpha[map[y][x] - 'A'] = true;

        if(mx < sum){
            mx = sum;
        }

        for(int dir=0;dir<4;dir++){
            int lx = x + dx[dir];
            int ly =  y + dy[dir];

            sum++;
            dfs(lx,ly);
            sum--;
        }

        alpha[map[y][x] - 'A'] = false;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> r >> c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> map[i][j];
        }
    }
    
    dfs(0,0);
    cout << mx <<'\n';
    return 0;
}