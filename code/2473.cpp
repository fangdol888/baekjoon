#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n; // 3~5000
vector<long long> input;
int main(){
    cin >> n;
    input.resize(n);
    for(int i =0 ;i<n;i++){
        cin >> input[i];
    }
    
    sort(input.begin(), input.end());

    
    return 0;
}