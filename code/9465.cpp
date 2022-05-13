#include <iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    int mx = 0;
    cin >> t;

    for(int i=0;i<t;i++){
        int n;
        cin >> n;

        int map[2][100001];
        int dp[2][100001];

        for(int r=0;r<2;r++)
        {
            for(int c=1;c<=n;c++){
                cin >> map[r][c];
            }
        }

        dp[0][0] = dp[1][0] = 0;
        dp[0][1] = map[0][1];
        dp[1][1] = map[1][1];

        for(int c=2;c<=n;c++){
            dp[0][c] = max(dp[1][c - 1], dp[1][c - 2]) + map[0][c];
            dp[1][c] = max(dp[0][c - 1], dp[0][c - 2]) + map[1][c];
        }


        cout << max(dp[0][n] , dp[1][n]) << '\n';
        

    }
    return 0;
}