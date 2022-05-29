#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,k;
vector<int> code;
vector<int> f;
vector<int> fr;
vector<int> r;


void createFail(){
    int i=1,j=0,n=code.size();
    while(i<n){
        while(j>0&&code[i] != code[j]){
            j = f[j-1];
        }
        if(code[i] == code[j]){
            f[i] = ++j;
        }
        i++;
    }

    i=1;j=0;n=r.size();

    while(i<n){
        while(j>0&&r[i] != r[j]){
            j = fr[j-1];
        }
        if(r[i] == r[j]){
            fr[i] = ++j;
        }
        i++;
    }
}

int main(){

    vector<vector<int>> v; // 저장용
    cin >> n >> k;

    v.resize(n);

    code.resize(k);// 어짜피 k이상이면 최소 k는 겹치므로 k개만 확인하면됨
    f.resize(k);
    fr.resize(k);
    r.resize(k);
    
    for(int i=0;i<n;i++){ //입력
        int m;
        cin >> m;
        v[i].resize(m);
        for(int j=0;j < m;j++){
            cin >> v[i][j];
        }
    }

    for(int start=0;start+k<=v[0].size();start++){ // 임의로 한 줄에 대해서 코드 조사

       for(int j=0;j<k;j++){ //코드 추출
            code[j] = v[0][start + j];
            r[k - j - 1] = v[0][start+j];//역코드
        }
        createFail();

        bool flag = false;

        for(int re=1;re<n;re++){ //모든 문자열 조사
            flag  =  false;

            for(int i=0,j=0;i<v[re].size();i++) // 주어진 문자열에 대해 KMP 알고리즘 수행
            {
                while(j>0 && v[re][i] != code[j])
                    j = f[j-1];

                if(v[re][i] == code[j]){
                    if(j == k - 1){//찾았으면 탈출
                        flag = true;
                        break;
                    }
                    j++;
                }
            }

            if(flag){ //찾았으면 다음 문자열 조사
                continue;
            }

            for(int i=0,j=0;i<v[re].size();i++) // 역문자열에 대해 KMP 알고리즘 수행
            {
                while(j>0 && v[re][i] != r[j])
                    j = fr[j-1];
                    
                if(v[re][i] == r[j]){ 
                    if(j == k - 1){
                        flag = true; //하나라도 찾았으면
                        break;
                    }
                    j++;
                }
            }

            if(!flag){ //둘 다 못찾았으면 탈출
                break;
            }
        }

        if(flag){ //모든 문자에 대해 찾았다면
            cout << "YES" << '\n';
            return 0;
        }
        //못찾았으면 다음 코드로 진행
    }

    cout << "NO" << '\n';
    return 0;
}