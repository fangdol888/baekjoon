#include <iostream>
#include <vector>
#define INF 10000000;
using namespace std;
int v, e;
struct Edge{
    int v,w;
}; 
vector<vector<Edge>> edge;

void dijstra(int num){
    
}

int main(){
    cin >> v >> e;
    edge.resize(v+1);

    for(int i=0;i<v;i++){
        int u,v,w;
        cin >> u >> v >> w;
        edge[u].push_back({v,w});
    }

    
    return 0;
}