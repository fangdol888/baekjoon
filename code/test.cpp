#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
double sum = 0;
int x1;
int y1;
int prex, prey;
double cc(int a1,int a2, int b1, int b2){
    a1 -= x1;
    a2 -= y1;
    b1 -= x1;
    b2 -= y1;
    sum += (a1*b2 - a2*b1)/2;
}
int main(){

    cin >> n;
    cin >> x1;
    cin >> y1;
    prex = x1;
    prey = y1;
    for(int i=1;i<n;i++){ //n-1 번
        int x,y;
        cin >> x >> y;
        cc(prex,prey,x,y);
        prex=x;
        prey=y;
    }

    if(sum<0) sum = -sum;

    cout << fixed;
    cout.precision(1);
    cout << sum << '\n';

    return 0;
}