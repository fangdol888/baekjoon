#include <iostream>
#include <vector>
using namespace std;

int L;
string str;
vector<int> f;// 길이당 최소 겹치는 부분 조사
int main(){
    cin >> L;
    cin >> str;
    f.resize(L);


    for(int i=1,j=0;i<L;i++){
        while(j>0 && str[i] != str[j]){ //j=0이거나 같은 문자 나올때까지 이동
            j = f[j-1];
        }
        //만약 같은문자면 현재까지 겹치는 수 대입
        if(str[i]==str[j]){
            f[i] = ++j;
        }
        //j==0 이고 str[i] != str[j] 이면 다음줄로 넘어감
    }
    cout << L - f[L-1] << '\n';
    return 0;
}