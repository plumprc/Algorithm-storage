#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
int n, m, eu, ev, cnt, res, a[5005];
struct node{
    int u, v, w;
    inline bool operator<(const node& t) const{
        return w < t.w;
    }
}edge[200005];

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

int query(int pos){
    int root = pos, tmp;
    while(root != a[root])
        root = a[root];
    while(pos != a[pos]){
        tmp = a[pos];
        a[pos] = root;
        pos = tmp;
    }
    return root;
}

void kruskal(){
    sort(edge, edge + m);
    for(int i = 0; i < m; i++){
        eu = query(edge[i].u);
        ev = query(edge[i].v);
        if(eu == ev) continue;
        else{
            // 最生成树的路径和
            res += edge[i].w;
            a[eu] = ev; cnt++;
            if(cnt == n - 1)
                break;
        }
    }
}

int main(){
    n = read(); m = read();
    for(int i = 1; i <= n; i++)
        a[i] = i;
    for(int i = 0; i < m; i++){
        edge[i].u = read();
        edge[i].v = read();
        edge[i].w = read();
    }
    kruskal();
    printf("%d", res);
    return 0;
}