#include <iostream>
#include <vector>
using namespace std;
int n,m;
struct App{
    int mem;
    int cost;
    
};

vector<App> app;
int dp[101][10001]; // n , c

void print(){
    for(int i=0;i <n ;i++){
        cout << app[i].mem << ' '<< app[i].cost << '\n';
    }
}

int main(){
    cin >> n >> m;
    app.resize(n+1);

    for(int i=1;i<=n;i++){
        cin >> app[i].mem;
    }
    for(int i=1;i<=n;i++){
        cin >> app[i].cost;
    }
    int res = 1000000000;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=10000;j++){
            if(j - app[i].cost >= 0 ){
                dp[i][j] = max(dp[i][j], dp[i-1][j-app[i].cost] + app[i].mem); // 현재 또는 이전 상태에서  
            }
            
            dp[i][j] = max(dp[i][j], dp[i-1][j]); //현재 또는 이전 상태 중 메모리크기가 큰 거
            
            if(dp[i][j] >= m) res = min(res , j);
        }
        
    }
    // print();
    cout << res << '\n';

    return 0;
}