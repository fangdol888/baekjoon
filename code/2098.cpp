#include <iostream>
#include <vector>
#define MAX 987654321
using namespace std;
int n;

int d[16][16];
int dp[16][1 << 16];

int tsp(int cur, int visited ){
    int& ret = dp[cur][visited];

    
    if(visited == (1<<n) - 1){ //모든 마을 방문 했다면
        if(d[cur][0] != 0) //원위치로 이동 가능? 
            return d[cur][0]; //그러면감
        return MAX; //순회 불가
    }

    if(ret != -1) // 원래 값 있으면 불러오기
        return ret;

    ret = MAX;
    for(int i=0;i<n;i++){ //다음
            if(visited & (1<<i) ||  d[cur][i] == 0) continue; //방문 했거나 갈 수 없다면 패스
              ret = min(ret, tsp(i, visited | (1<<(i))) + d[cur][i]);
    }

    return ret;
}

int main(){
    
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> d[i][j];
        }
    }
    fill(&dp[0][0], &dp[15][(1 << 16) - 1], -1);

    cout << tsp(0,1);

    return 0;
}