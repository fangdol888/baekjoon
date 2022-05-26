#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<long> resol;

int main(){
    cin >> n;
    resol.resize(n);
    for(int i=0;i<n;i++){
        cin >> resol[i];
    } 
    int start= 0,end = n-1;
    long min = 2000000000;
    unsigned int x,y;

    while(start<end){
        if( min >= abs(resol[end] + resol[start])){ //절댓값이 가장 작도록 유도
            min = abs(resol[end] + resol[start]);
            x = start;
            y = end;
        }
        
        if(resol[end] + resol[start] >0){
            end--;
        }
        else{
              start++;
        }

    }

    cout << resol[x] <<  ' ' << resol[y] <<'\n';
    return 0;
}