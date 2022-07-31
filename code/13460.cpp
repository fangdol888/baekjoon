#include <iostream>
#include <queue>
using namespace std;
int n,m; // 세로, 가로
char map[11][11];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

struct Point{
    int x, y;
    bool operator== (Point a){
        return x == a.x && y == b.x;
    }
};
struct Stage
{
    int stage;
    Point R,B;
};

Point hole, r, b;

void bfs(){
    queue<Stage> q;
    q.push({0, r, b});

    while(!q.empty()){

        auto cur = q.front(); q.pop();

        if(cur.stage > 10){
            cout << -1 << '\n';
        }

        if(cur.R == hole){
            cout << cur.stage << '\n';
            return;
        }else if(cur.B == hole){
            continue;
        }

        cur.stage++;

        for(int dir =0;dir<4;dir++){
            auto copy = cur;
            move(dir, copy.R, copy.B);
            q.push(copy);
        }
    }
}

bool avail(Point p){
    return !(p.x < 0 || p.y < 0 || p.x >= m || p.y >= n || map[p.y][p.x] == '#');
}

void move(int dir, Point& r, Point& b){

    do{
        r.x += dx[dir];
        r.y += dy[dir];
        b.x += dx[dir];
        b.y += dy[dir];

        if(map[r.y][r.x] == 'O' && map[b.y][b.x] == 'O'){
            return;
        }

    }
    while(avail(r) && avail(b) && map[r.y][r.x] != 'B' && map[b.y][b.x] != 'R');

    r.x -= dx[dir];
    r.y -= dy[dir];
    b.x -= dx[dir];
    b.y -= dy[dir];

}


int main(){
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> map[i][j];

            if(map[i][j] == 'O'){
                hole.x = j;
                hole.y = i;
            }else if (map[i][j] == 'R'){
                map[i][j] = '.';
                r.x = j;
                r.y = i;
            }else if (map[i][j] == 'B'){
                map[i][j] = '.';
                b.x = j;
                b.y = i;
            }
        }
    }

    bfs();

    return 0;
}