#include <iostream>
using namespace std;

double m[2];
int x[2][2];
int y[2][2];

double cross[2];


double getCross(){//교차점 구하기
    cross[0] = -( (-m[0] * x[0][0] + y[0][0]) - (-m[1] * x[1][0] + y[1][0]) )/(m[0]-m[1]);
    cross[1] = (m[0]*cross[0] + (-m[0] * x[0][0] + y[0][0]));
}

bool inScope(int line){ //직선 위 교차점 확인
    getCross();

    int tx[2] = {x[line][0], x[line][1]};
    int ty[2] = {y[line][0], y[line][1]};
    
    if(tx[0] > tx[1]){
        int t = tx[0];
        tx[0] = tx[1];
        tx[1] = t;
    }

    if(ty[0] > ty[1]){
        int t = ty[0];
        ty[0] = ty[1];
        ty[1] = t;
    }

    return (cross[0] >= tx[0] && cross[0] <= tx[1]) && (cross[1] >= ty[0] && cross[1] <= ty[1]);
}

bool xCross(int point, int line ){
    int f = x[line][0];
    int e = x[line][1];
    if(f > e){
        int t = f;
        f = e;
        e = t;
    }

    return (point >=f && point <=e);

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cin >> x[i][j] >> y[i][j];
        }
        m[i] = (double)(y[i][1]-y[i][0])/(x[i][1]-x[i][0]); //기울기 구하기
    }
    double det = m[1] - m[0];

    if(det == 0){ //부정(같은 기울기)
        if((-m[0] * x[0][0] + y[0][0]) ==  (-m[1] * x[1][0] + y[1][0])){ // 같은 직선 일 때
            if(xCross(x[0][0], 1) || xCross(x[0][1], 1) || xCross(x[1][0], 0) || xCross(x[1][1], 0)){ // 다른 직선 범위 내에 겹치는 부분이 있다면
                cout << 1 << '\n';
            }else cout << 0 << '\n';
        }
        else cout << 0 <<'\n'; //평행
    }else{ //교차점 있을때 
        if(inScope(0) && inScope(1)){ //교차점이 두 직선 위에 동시에 존재하는가
            cout << 1 << '\n';
        }else cout << 0 << '\n';
        
    }
    return 0;
}