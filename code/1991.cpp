#include <iostream>
#include <vector>
using namespace std;

struct Node{
    int left;
    int right;
};

vector<Node*> nod;

int n;
int c2n(char a){
    return (a != '.') ? static_cast<int>(a - 'A') : -1;
}
char n2c(int a){
    return (a + 'A');
}

void preorder(int cur){
    cout << n2c(cur);
    if(nod[cur]->left != -1) preorder(nod[cur]->left);
    if(nod[cur]->right != -1) preorder(nod[cur]->right);
}
void postorder(int cur){
    if(nod[cur]->left != -1) postorder(nod[cur]->left);
    if(nod[cur]->right != -1) postorder(nod[cur]->right);
    cout << n2c(cur);
}
void inorder(int cur){

    if(nod[cur]->left != -1) inorder(nod[cur]->left);
    cout << n2c(cur);
    if(nod[cur]->right != -1) inorder(nod[cur]->right);
}

int main(){
    cin >> n;
    nod.resize(n+1);
    for(int i=0;i<n;i++){
        char cur, l,r;
        cin >> cur >> l >> r;
        nod[c2n(cur)] = new Node{c2n(l), c2n(r)};
    }
    preorder(0);cout <<'\n';
    inorder(0);cout <<'\n';
    postorder(0);cout <<'\n';
    return 0;
}