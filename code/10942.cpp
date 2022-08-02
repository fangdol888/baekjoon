#include <iostream>
#include <vector>
using namespace std;

int n,m;
vector<int> su;
bool dp[2001][2001];

void make(){

    for(int i=0;i<=n;i++){
        for(int j=0;j <= n-i;j++){
            int row = j;
            int col = i + j;
            if(row == col) dp[row][col] = true;
            else if(row + 1 > col - 1){ 
                if(su[row] == su[col]) dp[row][col] = true;
            }else{
                dp[row][col] = dp[row+1][col-1] && (su[row] == su[col]);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;su.resize(n+1);
    for(int i=1;i<=n;i++){  
        cin >> su[i];
    }

    make();

    cin >> m;

    for(int i=0;i<m;i++){
        int start, end;
        cin >> start >> end;
        cout << dp[start][end] << '\n';
    }

    return 0;
}