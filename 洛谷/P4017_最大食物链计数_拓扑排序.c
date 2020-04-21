#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#define mod 80112002

using namespace std;
int n, m, res, ind[5005], outd[5005], f[5005];
vector<int> edge[5005];
queue<int> q;

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

int main(){
    n = read(); m = read();
    for(int i = 1; i <= m; i++){
        int x = read(), y = read();
        edge[x].push_back(y);
        ind[y]++; outd[x]++;
    }
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
            f[i] = 1;
        }
    }
    while(!q.empty()){
        int lhs = q.front();
        q.pop();
        for(int i = 0; i < edge[lhs].size(); i++){
            int u = edge[lhs][i];
            ind[u]--;
            if(ind[u] == 0) q.push(u);
            f[u] = (f[u] + f[lhs]) % mod;
        }
    }
    for(int i = 1; i <= n; i++){
        if(outd[i] == 0)
            res = (res + f[i]) % mod;
    }
    cout << res;
    return 0;
}