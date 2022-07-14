#include <iostream>
#include <queue>
#define MAX 5

using namespace std;
int n;

int map[MAX+1][20][20];
int line[20];

void print(int count = 1){
    cout << '\n';
    cout << count << ':' << '\n';
    for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout << map[count][i][j] << ' ';
            }
            cout << '\n';
        }
    cout << '\n';
}

// down, right, up, left
void move(int dir){
    int temp = 0;

    if(dir == 0){ //왼쪽으로
        int insIdx = 0;

            for(int j=0;j<n;j++){
                if(line[j] == 0){ //빈공간
                    continue;
                }
                if(temp == line[j]){ //이전값하고 동일하면 합병
                    line[insIdx-1] *= 2;
                    line[j] = 0;
                    temp = 0; //초기화
                }else{ 
                    temp = line[j];
                    if(insIdx != j) {line[j] = 0;}
                    line[insIdx++] = temp;
                    
                    
                }
            }

    }else{ //오른쪽으로
        int insIdx = n-1;

        for(int j=n-1;j>=0;j--){

                if(line[j] == 0){ //빈공간
                    continue;
                }

                if(temp == line[j]){ //이전값하고 동일하면 합병
                    line[insIdx+1] *= 2;
                    line[j] = 0;
                    temp = 0; //초기화
                }else{ 
                    temp = line[j];
                    if(insIdx != j) {line[j] = 0;}
                    line[insIdx--] = temp;
                    
                    
                }
            }
    }
}

int solve(int count){ // dfs
    if(count == 0){
        int mx = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mx < map[0][i][j]) mx = map[0][i][j];
            }
        }

       
        return mx;

    }else{
        int res = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                line[j] = map[count][j][i];
            }
            //up
            move(0);

            for(int j=0;j<n;j++){
                map[count-1][j][i] = line[j];
            }
        }
        print(count-1);
        res = max(res, solve(count-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                line[j] = map[count][j][i];
            }
            //down
            move(1);

            for(int j=0;j<n;j++){
                map[count-1][j][i] = line[j];
            }
        }print(count-1);
        res = max(res, solve(count-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                line[j] = map[count][i][j];
            }
            //left
            move(0);

            for(int j=0;j<n;j++){
                map[count-1][i][j] = line[j];
            }
        }print(count-1);
        res = max(res, solve(count-1));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                line[j] = map[count][i][j];
            }
            //right
            move(1);

            for(int j=0;j<n;j++){
                map[count-1][i][j] = line[j];
            }
        }print(count-1);
        res = max(res, solve(count-1));

       return res;
    }       

}
int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> map[MAX][i][j];
        }
    }

   cout << solve(MAX);

    return 0;
}