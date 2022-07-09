#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int n; // 3~5000

long long sum = 3000000001;

vector<long long> input;

int main(){
    cin >> n;
    input.resize(n);

    for(int i =0 ;i<n;i++){
        cin >> input[i];
    }
    
    sort(input.begin(), input.end());

    long long ans[3] ={0,};

    for(int i=0;i<n-2;i++){
        int left = i+1;
        int right = n-1;

        while(left < right){
            long long temp = input[i] + input[left] + input[right];
            
            if(sum > abs(temp)){
                sum = abs(temp);
                ans[0] = input[i];
                ans[1] = input[left];
                ans[2] = input[right];
            }

            if(temp < 0) left++;
            else right--;
        }
    }

    for(int i=0;i<3;i++){
        cout << ans[i] << ' ';
    }
    cout << '\n';
    return 0;
}