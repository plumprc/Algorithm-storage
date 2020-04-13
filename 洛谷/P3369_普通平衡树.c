#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int root, n, snt, opt, num;
const int MAX = (1e+5) + 10;
struct node{
    int father, val, siz, cnt;
    int ch[2];
}sp[MAX];

void update(int pos){
    sp[pos].siz = sp[sp[pos].ch[0]].siz + sp[sp[pos].ch[1]].siz + sp[pos].cnt;
}

int identify(int pos){
    return sp[sp[pos].father].ch[0] == pos? 0 : 1;
}

void connect(int pos, int fa, int son){
    sp[pos].father = fa;
    sp[fa].ch[son] = pos;
}

void rotate(int pos){
    int y = sp[pos].father;
    int R = sp[y].father;
    int Rson = identify(y);
    int yson = identify(pos);
    int B = sp[pos].ch[yson ^ 1];
    connect(B, y, yson); connect(y, pos, (yson ^ 1));
    connect(pos, R, Rson);
    update(y); update(pos);
}

void splay(int pos, int goal){
    while(sp[pos].father != goal){
        int up = sp[pos].father;
        if(sp[up].father == goal)
            rotate(pos);
        else if(identify(up) == identify(pos)){
            rotate(up); rotate(pos);
        }
        else{
            rotate(pos); rotate(pos);
        }
    }
    if(goal == 0)
        root = pos;
}

void insert(int x){
    int u = root, fa = 0;
    while(u && sp[u].val != x){
        fa = u;
        u = sp[u].ch[x > sp[u].val]; // 大于则右插
    }
    if(u)
        sp[u].cnt++;
    else{
        u = ++snt;
        if(fa)
            sp[fa].ch[x > sp[fa].val] = u;
        sp[snt].ch[0] = sp[snt].ch[1] = 0;
        sp[snt].father = fa; sp[snt].val = x;
        sp[snt].cnt = sp[snt].siz = 1;
    }
    splay(u, 0);
}

void queryVal(int x){
    int u = root;
    if(!u) return;
    while(sp[u].ch[x > sp[u].val] && x != sp[u].val)
        u = sp[u].ch[x > sp[u].val];
    splay(u, 0);
}

int queryNext(int x, int f){
    queryVal(x);
    int u = root;
    if((sp[u].val > x && f) || (sp[u].val < x && !f))
        return u;
    u = sp[u].ch[f];
    while(sp[u].ch[f ^ 1])
        u = sp[u].ch[f ^ 1];
    return u;
}

void del(int x){
    int pre = queryNext(x, 0);
    int post = queryNext(x, 1);
    splay(pre, 0); splay(post, pre);
    int d = sp[post].ch[0];
    if(sp[d].cnt > 1){
        sp[d].cnt--;
        splay(d, 0);
    }
    else sp[post].ch[0] = 0;
}

int query_k(int k){
    int u = root;
    if(sp[u].siz < k)
        return -1;
    while(true){
        int y = sp[u].ch[0];
        if(k > sp[y].siz + sp[u].cnt){
            k -= sp[y].siz + sp[u].cnt;
            u = sp[u].ch[1];
        }
        else if(sp[y].siz >= k)
            u = y;
        else return sp[u].val;
    }
}

int main(){
    cin >> n;
    insert(-2147483647);
    insert(+2147483647);
    while(n--){
        cin >> opt >> num;
        if(opt == 1)
            insert(num);
        else if(opt == 2)
            del(num);
        else if(opt == 3){
            queryVal(num);
            cout << sp[sp[root].ch[0]].siz << endl;
        }
        else if(opt == 4)
            cout << query_k(num + 1) << endl;
        else if(opt == 5)
            cout << sp[queryNext(num, 0)].val << endl;
        else cout << sp[queryNext(num, 1)].val << endl;
    }
    return 0;
}