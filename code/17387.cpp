#include <iostream>
using namespace std;

long long x[2][2];
long long y[2][2];

long long ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
    long long ans = (x2 -x1) * (y3-y1) - (y2-y1) * (x3-x1);
    if(ans < 0){ // 시계방향
        return -1;
    }else if(ans >0){
        return 1;
    }else return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> x[i][j] >> y[i][j];
        }
    }
    long long d1 = ccw(x[0][0], y[0][0], x[0][1], y[0][1], x[1][0], y[1][0]) * ccw(x[0][0], y[0][0], x[0][1], y[0][1], x[1][1], y[1][1]);
    long long d2 = ccw(x[1][0], y[1][0], x[1][1], y[1][1], x[0][0], y[0][0]) * ccw(x[1][0], y[1][0], x[1][1], y[1][1], x[0][1], y[0][1]);
    
    if(d1 <= 0 && d2 <= 0){
        if(d1 == 0 && d2 == 0){ // 둘다 평행일 때,
            if(x[0][0] == x[1][0]){
                if(y[0][0] >= y[0][1]) swap(y[0][0] , y[0][1]);
                if(y[1][0] >= y[1][1]) swap(y[1][0], y[1][1]);
                if(y[0][0] <= y[1][1] && y[1][0] <= y[0][1])
                    cout << 1 << '\n';
                else cout << 0 << '\n';
            }else{
                if(x[0][0] > x[0][1]) swap(x[0][0] , x[0][1]);
                if(x[1][0] > x[1][1]) swap(x[1][0], x[1][1]);
                if(x[0][0] <= x[1][1] && x[1][0] <= x[0][1])
                    cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            

        }
        else cout << 1 << '\n';
    }
    else cout << 0 << '\n';

    return 0;
}