#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge{
    int start;
    int end;
    int weight;
};

bool comp(Edge a, Edge b){
    if(a.weight == b.weight) return a.start < b.start;
    return a.weight < b.weight;
}

int v, e;
int mst_weight = 0;
vector<int> group;
vector<Edge> ed;

int find_group(int x)
{
    if(group[x] == x) return x;
    else return group[x] = find_group(group[x]);
}

bool same_group(int x, int y)
{
    x= find_group(x);
    y = find_group(y);
    if(x==y) return true;
    else return false;
}

void union_group(int x, int y){
    x = find_group(x);
    y = find_group(y);
    (x!=y)?group[y]=x:0;
}

int main(){
    cin >> v >> e;
    group.resize(v+1);

    for(int i=0;i<e;i++){
        int a,b,c;
        cin >> a >> b >> c;// a -> b (with c weight (c < 0 is possible))
        ed.push_back({a,b,c});
    }
    for(int i=0;i<=v;i++){
        group[i] = i;
    }
    
    sort(ed.begin(), ed.end(),comp);
    
    
    for(auto t : ed){ //간선 찾기
        if(!same_group(t.start, t.end)){
            union_group(t.start, t.end);
            mst_weight += t.weight;
        }
    }

    cout << mst_weight << '\n';

    system("pause");
    return 0;
}