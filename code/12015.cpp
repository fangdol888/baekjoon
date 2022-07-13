#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(v.empty() || v.back() < temp){
            v.push_back(temp);
        }else{
            *lower_bound(v.begin(), v.end(), temp) = temp;
        }
    }

    cout << v.size() <<'\n';
    return 0;
}