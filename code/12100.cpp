#include <iostream>
#include <queue>
#define MAX 5

using namespace std;
int n;

int map[20][20];
int line[20];
bool visit[20];

// down, right, up, left
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0}; 

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[i][j];
        }
    }

    

    return 0;
}