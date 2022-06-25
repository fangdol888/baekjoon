#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sosu;
bool so[4000001];
int n;
int sum = 0;
int s = 0, e = 0;
int res = 0;

int main(){
    cin >> n;
    
    for(int i=2;i<=n;i++){
        if(!so[i]){ //소수면
            sosu.push_back(i);
            for(int j=1; j*i <= n; j++){
                so[j*i] = true;
            }
        }
    }
    
    sum = 0;
    s=0, e=0;
    
    for(auto& s:sosu) cout << s << ' ';
    cout << '\n';

    while(s<=e){ //2 pointer
        if(sum > n){
            sum -= sosu[s++];
        }
        else if(sum < n){
            if(e >= sosu.size()) break;
            sum += sosu[e++];
        }
        else{
            res++;
            if(e >= sosu.size()) break;
            sum += sosu[e++];
        }
    }

    cout << res << '\n';

    return 0;
}