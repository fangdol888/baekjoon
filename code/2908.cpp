#include <iostream>
using namespace std;

int reverse(int num){
    int res = 0;
    while(num!=0){
        res*=10;
        res+=num%10;
        num/=10;
    }
    return res;
}

int in[2];

int main(){
    cin >> in[0] >> in[1];
    in[0] = reverse(in[0]);
    in[1] = reverse(in[1]);
    if(in[0] > in[1]){
        cout << in[0] << '\n';
    }else cout << in[1] << '\n';
    
    return 0;
}