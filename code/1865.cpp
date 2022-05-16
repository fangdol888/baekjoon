#include <iostream>
#include <vector>
#define MAX 100000000
using namespace std;
int tc;

vector<vector<int>> road;

void bellmanFord(int n) {
    for (int i = 0; i < n; i++) {
        for (int pos = 0; pos < v.size(); pos++) {
            int from = v[pos].first.first;
            int to = v[pos].first.second;
            int cost = v[pos].second;

            if (dist[from] + cost < dist[to]) dist[to] = dist[from] + cost;
        }
    }

    for (int pos = 0; pos < v.size(); pos++) {
        int from = v[pos].first.first;
        int to = v[pos].first.second;
        int cost = v[pos].second;
        if (dist[from] + cost < dist[to]) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";

}

int main(){
    cin >> tc;
    
    for(int test=0;test<tc;test++){
        int n, m, w;
        cin >> n >> m >> w;

        road.resize(n+1);
        for(int i=1;i<=n;i++){
            road[i].resize(n+1);
            for(int j=1;j<=n;j++){
                road[i][j] = MAX;
            }
        }

        for(int i=0;i<m;i++){
            int s,e,t;
            cin >> s >> e >> t;
            
            if(road[s][e] == MAX){
                road[s][e] = {t};
            }else if(road[s][e] > t){
                road[s][e] = {t};
            }
        }

        for(int i=0;i<w;i++){
            int s,e,t;
            cin >> s >> e >> t;
            if(road[s][e] == MAX){
                road[s][e] = {-t};
            }else if(road[s][e] > -t){
                road[s][e] = {-t};
            }
        }

        //floyd washall
        /*
        for(int mid=1;mid<=n;mid++){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    if(road[i][mid] != MAX && road[mid][j] != MAX){
                        if(road[i][j] > road[i][mid] + road[mid][j])
                        {
                            road[i][j] = road[i][mid] + road[mid][j];
                        }
                    }
                }   
            }
        }*/

        //belman ford
        for(int i=0;i<)
        
        int dis = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(road[i][j] != MAX && road[j][i] !=MAX &&  road[i][j] + road[j][i] < 0){
                    cout << "YES" <<'\n';
                    return 0;
                }
            }
        }
        cout << "NO"<<'\n';
    }

    return 0;
}