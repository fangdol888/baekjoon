#include <iostream>
#include <vector>
using namespace std;
int n;
string p;

vector<string> fibo;
vector<int> fail;

void makeFail(){
    int m = p.size();
    for(int i=1,j=0;i<m;i++){
        while(j>0 && p[i] != p[j]){
            j = fail[j-1];
        }
        if(p[i] == p[j])
            fail[j] = ++j;
    }
}

void fib(){
    fibo.resize(100);
    fibo[0] = "0";
    fibo[1] = "1";

    for(int i=2;i<100;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
        cout << fibo[i] << '\n';
    }
}

int main(){
    fib();
    for(int tc=1;tc < 5;tc++){
        cin >> n;
        cin >> p;

        makeFail();
        int sum = 0;
        int m = p.size();
        for(int i=1,j=0;i<m;i++){
            while(j>0 && p[i] != p[j]){
            j = fail[j-1];
        }
            if(p[i] == p[j]){
                if(j == m-1){
                    sum++;
                }
                else{
                    j++;
                }
            }
        }
        cout << "Case " << tc << ": " << sum << '\n';
    }

    return 0;
}