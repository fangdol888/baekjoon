#include <iostream>
#include <vector>
using namespace std;
int test;
int n;
int ans = 0;
vector<int> stu;
vector<bool> visit;
vector<bool> done;

int sum =0 ;

void hasCycle(int node){
    visit[node] = true;
    int next = stu[node];

    if(!visit[next]){
        hasCycle(next);
    }else if(!done[next]){
        for(int i=next; i!=node; i=stu[i]){
            ans++;
        }
        ans++;
    }

    done[node] = true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> test;

    for(int t=0;t<test;t++){
        cin >> n;
        stu.resize(0);visit.resize(0);
        stu.resize(n+1);visit.resize(n+1);
        done.resize(0);done.resize(n+1);

        ans = 0;

        for(int i=1;i<=n;i++){
            cin >> stu[i];   
        }

        for(int i=1;i<=n;i++){
            if(!visit[i]){
                hasCycle(i);
            }
        }
        cout << n - ans << '\n';
    }

    return 0;
}