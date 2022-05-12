#include <iostream>
#define SIZE 1025
using namespace std;
int n,m ;
int map[SIZE][SIZE];
int summap[SIZE][SIZE];

int x[2],y[2];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >>n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> map[i][j];
            summap[i][j] = summap[i][j-1] +summap[i-1][j] - summap[i-1][j-1] + map[i][j];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin >> x[j] >> y[j];
        }
        int sum =0;
        sum = summap[x[1]][y[1]] - summap[x[1]][y[0]-1] - summap[x[0]-1][y[1]] + summap[x[0]-1][y[0]-1];
        cout << sum << '\n';
    }
    return 0;
}