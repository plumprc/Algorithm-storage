#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, a, b, bnt;
struct node{
    int val, ch[2];
}BST[100005];

void insert(int pos, int x){
    int u = BST[pos].ch[1];
    int tmp = u;
    while(u){
        tmp = u;
        u = BST[u].ch[x > BST[u].val];
    }
    bnt++;
    BST[tmp].ch[x > BST[tmp].val] = bnt;
    BST[bnt].val = x;
}

int query(int pos, int x){
    int u = BST[pos].ch[1];
    while(u && BST[u].val != x)
        u = BST[u].ch[x > BST[u].val];
    if(BST[u].val == x)
        return u;
    else return 0;
}

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        insert(0, a);
    }

    cin >> b;
    while(b--){
        cin >> a;
        cout << query(0, a) << endl;
    }
    return 0;
}