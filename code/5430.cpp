#include <iostream>
#include <vector>
using namespace std;
int t;

int main(){
    cin >> t;
    for(int test=0;test<t;test++){
        string oper;
        cin >> oper;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        vector<int> array;

        int i = 1;
        int sum = 0;

        while(i<arr.size()){
            if(arr[i] == ','){
                array.push_back(sum);
                sum=0;
                i++;
            }
            else if(arr[i] == ']'){
                if(arr[i-1] == '[') break;
                array.push_back(sum);
                break;
            }
            else{
                sum *= 10;
                sum += (arr[i] - '0');
                i++;
            }
        }

        int dir = 1; // 1: right, -1 : left
        int left = 0;
        int right = array.size() - 1;
        bool flag = false;
        for(auto op : oper){
            if(op == 'R'){
                dir *= -1;
            }else{ //
                if(n==0){
                    cout << "error" << '\n';
                    flag=true;
                    break;
                }
                
                if(dir == 1){
                    left++;

                }else{
                    right--;
                }

                n--;
            }

        }
        if(flag) continue;
        else if (n == 0) {
            cout << "[]"<<'\n';
            continue;
        }

        cout << '[';

            if(dir == 1){
                for(int i = left; i < right; i++)
                    cout << array[i] << ',';
            }else{
                for(int i = right; i > left; i--)
                    cout << array[i] << ',';
            }

        if(dir == 1){
                cout << array[right];
        }else{
                cout << array[left];
        }
        cout << ']' <<'\n';
    }
    return 0;
}