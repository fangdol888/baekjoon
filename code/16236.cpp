#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

//priority : close distance, up, left
int dx[4] = {0,-1,1,0}; // up, left, right, down
int dy[4] = {-1,0,0,1};

int n, m;
int map[21][21]; //fish exist & size, shark position
int mov_time[21][21];
int shark_size = 2;
int eaten = 0;

bool isAvailable(int x, int y){
    if(x<0||y<0||y>=n||x>=n) return false;//범위를 지나면
    if(mov_time[y][x]!=-1) return false; //지나온 곳이면
    return true;
}

void reset_time(){
    fill(&mov_time[0][0],&mov_time[20][20],-1);

}
template<typename T>
void show_map(T& m){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool isFish(int x, int y){
    int s = map[y][x];
    return (s>0 && s<=6);
}

bool compare(pair<int,int> a, pair<int,int> b){
    if(mov_time[a.second][a.first] == mov_time[b.second][b.first]){ //같은 시간이면
        if(a.second == b.second) return a.first < b.first; // 같은 높이면 왼쪽부터
        return a.second < b.second; // 위쪽부터
    }
    return  mov_time[a.second][a.first] < mov_time[b.second][b.first];
}

int bfs(int x, int y){ // current shark position
    queue<pair<int, int>> q;
    q.push({x,y});
    
    reset_time();
    mov_time[y][x] = 0;

    int taken = 0;
    int mindst = 10000000;
    vector<pair<int,int>> min_pos;

    while(!q.empty()){ //더 이상 갈데가 없을때 까지
        auto cur = q.front();q.pop();
        int x = cur.first, y = cur.second;

        for(int dir=0;dir<4;dir++){
            int lx = x + dx[dir];
            int ly = y + dy[dir];

            if(isAvailable(lx,ly)){ //범위내의 지나오지 않은 곳이면
                if(isFish(lx,ly) && map[ly][lx] < shark_size){ // 작은 물고기 있는 위치면
                    min_pos.push_back({lx,ly}); //최소거리 위치 넣기

                }else if(map[ly][lx] > shark_size) continue; //큰 물고기면 안지나감
                
                q.push({lx,ly});
                mov_time[ly][lx] = mov_time[y][x] + 1;
            }
        }
    }

    if(min_pos.empty()) return 0;

    sort(min_pos.begin(), min_pos.end(), compare);

    int dx = min_pos[0].first, dy = min_pos[0].second; //최소값
    map[dy][dx] = 0; // 먹기
    if(shark_size == ++eaten){
        shark_size++;
        eaten=0;
    }
    taken += mov_time[dy][dx];
    taken += bfs(dx,dy);
    return taken;
}   

int main(){
    cin >> n;
    int x,y;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
            if(map[i][j] == 9){
                x = j;
                y = i;
                map[i][j] =0;
            }
        }
    }
    cout << bfs(x, y) << '\n';
    return 0;
}