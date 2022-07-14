#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> v;
vector<int> ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i=0;i<n;i++){
        int temp;
        cin >> temp;
        if(v.empty() || v.back() < temp){
            v.push_back(temp);
            ans.push_back(temp);
        }else{
            *lower_bound(v.begin(), v.end(), temp) = temp;
            
        }
    }

    cout << v.size() <<'\n';
    for(int i=0;i<v.size();i++){
        cout << v[i] << ' ';
    }cout << '\n';
    return 0;
}