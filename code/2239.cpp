#include <iostream>
#include <vector>
using namespace std;

int map[9][9];
int cnt = 0;
bool flag = false;

vector<pair<int,int>> vac;
bool visit[81] ={false,};

void print(){
 for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout << map[i][j];
            }
            cout <<'\n';
        }
}


bool possible(int x, int y, int num){

    //row , col
    for(int i=0;i<9;i++){
        if(map[y][i] == num || map[i][x] == num)
            return false;
    }
    //box
    int st_x = x/3;
    int st_y = y/3;
    
    for(int i=0;i<3;i++){
        for(int j=0;j < 3;j++){
            if(map[st_y*3 + i][st_x*3 + j] == num) return false;
        }
    }

    return true;
}


void dfs(int c){
    if(c == cnt){
        print();
        flag = true;
        return;
    }

    if(visit[c]) return;
        visit[c] = true;

        int x = vac[c].first;
        int y = vac[c].second;

        for(int k=1;k<=9;k++){

            if(possible(x , y,  k)){
                map[y][x] = k;
                dfs(c+1);
                map[y][x] = 0;
            }

        }
        if(flag) return;
        visit[c] = false;
    
}

int main(){

    for(int i=0;i<9;i++){
        string str;
        cin >> str;
        for(int j=0;j<9;j++){
            map[i][j] = (int)(str[j] - '0');
            
            if(map[i][j] == 0) {
                vac.push_back({j,i}); // x , y
                cnt++;
            } 
        }
    }
 
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(map[i][j] == 0){
                dfs(0);
                if(flag) break;
            }
        }
        if(flag) break;
    }

    return 0;
}