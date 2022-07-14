#include <iostream>
#include <vector>
#define INF INT32_MAX
using namespace std;
int n;
vector<pair<int,int>> matrix;
int dp[501][501];

int make(){
    for(int dis = 1; dis < n; dis++){ //행렬의 간격
        for(int i = 0 ; i < n - dis;i++){ //행렬 시작 위치
            dp[i][i+dis] = INF;
            for(int j=i; j <= i + dis ;j++){ //연산 최소값 중간 탐색
                dp[i][i+dis] = min(dp[i][i+dis], dp[i][j] + dp[j+1][i+dis] + matrix[i].first *matrix[j].second *matrix[i+dis].second);
            }
            
        }
    }

    return dp[0][n-1];
}

int main(){
    cin >> n;
    int a,b;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        matrix.push_back({a,b});
    }
    cout <<  make() << '\n';

    return 0;
}