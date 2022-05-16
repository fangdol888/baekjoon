#include <iostream>
#include <stack>
#include <string>

using namespace std;
stack<char> alpha;
stack<char> op;
bool isAlpha(char a){
    return 'A' <= a && a <= 'Z'; 
}

int main(){
    string s;
    cin >> s;
    for(auto c : s){
        if(isAlpha(c)){
            alpha.push(c);
        }else{
            op.push(c);
        }
    }
     
    return 0;
}