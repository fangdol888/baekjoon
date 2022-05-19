#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int tc, n;
int x, y;
pair<int,int> dot[21];

pair<int,int> group1;
pair<int,int> group2;
double min_length =1000000000.0;
bool visit[21]{};

double length(){
    group1 = group2 = {0,0};

   for(int i=0;i<n;i++){
       if(visit[i]){
            group1.first += dot[i].first;
            group1.second += dot[i].second;
       }else{
            group2.first += dot[i].first;
            group2.second += dot[i].second;
       }
   }  
    return sqrt(pow(group1.first-group2.first,2) + pow(group1.second-group2.second,2));
}

void dfs(int remain, int startidx){
    if(remain == 0){
        double len = length();

        if(min_length > len){
            min_length = len;
        }
    }else{
        for(int i=startidx;i<n;i++){
            if(!visit[i]){
                visit[i] = true;
                dfs(remain-1,i);
                visit[i] = false;
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> tc;
    for(int test=0;test<tc;test++){
        cin >> n;
        min_length =1000000000.0;
        for(int i=0;i<n;i++){
            cin >> dot[i].first >> dot[i].second; // first: x, second:   
        }
        dfs(n/2, 0);
        cout << fixed;
        cout.precision(7);
        cout << min_length << '\n';
    }
    return 0;
}