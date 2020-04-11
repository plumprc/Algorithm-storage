#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
const int INF = 0x7fffffff;
const int MAX = 5e+5 + 10;
int bnt, n, a, b;
struct node{
    int val, L, R, cnt, siz;
}BST[MAX];

void add(int pos, int val){
    BST[pos].siz++;
    if(BST[pos].val == val){
        BST[pos].cnt++;
        return;
    }
    if(BST[pos].val > val){
        if(BST[pos].L != 0)
            add(BST[pos].L, val);
        else{
            bnt++; // BST结点总数
            BST[bnt].val = val;
            BST[bnt].siz = BST[bnt].cnt = 1;
            BST[pos].L = bnt;
        }
    }
    else{
        if(BST[pos].R != 0)
            add(BST[pos].R, val);
        else{
            bnt++;
            BST[bnt].val = val;
            BST[bnt].siz = BST[bnt].cnt = 1;
            BST[pos].R = bnt;
        }
    }
}

int queryPre(int pos, int val, int res){
    if(BST[pos].val >= val){
        if(BST[pos].L == 0)
            return res;
        else return queryPre(BST[pos].L, val, res);
    }
    else{
        if(BST[pos].R == 0)
            return (BST[pos].val < val? BST[pos].val : res);
        if(BST[pos].cnt != 0)
            return queryPre(BST[pos].R, val, BST[pos].val);
        else return queryPre(BST[pos].R, val, res);
    }
}

int queryPost(int pos, int val, int res){
    if(BST[pos].val <= val){
        if(BST[pos].R == 0)
            return res;
        else return queryPost(BST[pos].R, val, res);
    }
    else{
        if(BST[pos].L == 0)
            return (BST[pos].val > val? BST[pos].val : res);
        if(BST[pos].cnt != 0)
            return queryPost(BST[pos].L, val, BST[pos].val);
        else return queryPost(BST[pos].L, val, res);
    }
}

int queryVal(int pos, int val){
    if(pos == 0) return 0;
    if(val == BST[pos].val)
        return BST[BST[pos].L].siz + 1;
    if(val < BST[pos].val)
        return queryVal(BST[pos].L, val);
    return queryVal(BST[pos].R, val) + BST[BST[pos].L].siz + BST[pos].cnt;
}

int querykth(int pos, int k){
    if(pos == 0) return INF;
    if(BST[BST[pos].L].siz >= k)
        return querykth(BST[pos].L, k);
    if(BST[BST[pos].L].siz + BST[pos].cnt >= k)
        return BST[pos].val;
    return querykth(BST[pos].R, k - BST[BST[pos].L].siz - BST[pos].cnt);
}

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        if(a == 1) cout << queryVal(1, b) + 1 << endl;
        else if(a == 2) cout << querykth(1, b) << endl;
        else if(a == 3) cout << queryPre(1, b, -INF) << endl;
        else if(a == 4) cout << queryPost(1, b, INF) << endl;
        else{
            if(bnt == 0){
                bnt++;
                BST[bnt].val = b;
                BST[bnt].siz = BST[bnt].cnt = 1;
            }
            else add(1, b);
        }
    }
    return 0;
}