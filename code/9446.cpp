#include <iostream>
#include <vector>
using namespace std;
int test;
int n;
int ans = -1;
vector<int> stu;
vector<int> visit;
int sum =0 ;

bool dfs(int par, int cur){
    if(par == cur){
        return true;
    }else{
        if(!visit[stu[cur]]){
            visit[stu[cur]] = true;
            return dfs(par, stu[cur]);
        }
        return false;
    }
    
}

int main(){
    cin >> test;
    for(int t=0;t<test;t++){
        cin >> n;
        stu.resize(0);visit.resize(0);
        stu.resize(n+1);visit.resize(n+1);
        sum = 0;

        for(int i=1;i<=n;i++){
            cin >> stu[i];   
        }
        for(int i=1;i<=n;i++){
            if(i == stu[i] || dfs(i, stu[i])){
                continue;
            }
            else sum++;
        }
        ans = sum;
        cout << ans << '\n';
    }
    return 0;
}