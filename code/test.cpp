#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
double sum = 0;
double xx[10001], yy[10001];

double cc(double a1,double a2, double b1, double b2){
    a1 -= xx[0];
    a2 -= yy[0];
    b1 -= xx[0];
    b2 -= yy[0];
    sum += (a1*b2 - a2*b1)/2.0;
    return sum;
}
int main(){


    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> xx[i] >> yy[i];
    }

    for(int i=1;i<n-1;i++){ 
        cc(xx[i], yy[i], xx[i+1], yy[i+1]);
    }

    cout.precision(1);
    cout << fixed;
    cout << abs(sum) << '\n';

    return 0;
}