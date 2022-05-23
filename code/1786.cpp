#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> fail;
string t,p;

void createFail(){
   int m = p.size(), j= 0;
   for(int i=1;i<m;i++){
        while(j>0 && p[i] != p[j]){
            j = fail[j-1];
        }
        if(p[i] == p[j]){
            fail[i] = ++j;
        }
   }
}

int main(){
    int sum = 0;
    vector<int> res;
    getline(cin,t);
    getline(cin,p);
    fail.resize(p.size());
    createFail();
    int j=0;
    for(int idx=0;idx<t.size();idx++){
       while(j>0 && t[idx] != p[j])
            j= fail[j-1];

       if(t[idx] == p[j]){
           if(j==p.size()-1){
                res.push_back(idx - p.size() + 1);
                j=fail[j];
           }else{
               j++;
           }
       }
    }

    cout << res.size() << '\n';
    for(auto d: res) cout << d+1 << ' ';

    //system("pause");
    return 0;
}