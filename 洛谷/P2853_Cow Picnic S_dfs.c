#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
int k, n, m, res, cow[1005], f[1005];
bool visited[1005];
vector<int> edge[1005];

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

void dfs(int pos){
    visited[pos] = true;
    f[pos]++;
    for(int i = 0; i < edge[pos].size(); i++){
        int u = edge[pos][i];
        if(!visited[u]) dfs(u);
    }
}

int main(){
    k = read(); n = read(); m = read();
    for(int i = 1; i <= k; i++)
        cow[i] = read();
    for(int i = 1; i <= m; i++){
        int u = read(), v = read();
        edge[u].push_back(v);
    }
    for(int i = 1; i <= k; i++){
        dfs(cow[i]);
        memset(visited, false, sizeof(visited));
    }
    for(int i = 1; i <= n; i++){
        if(f[i] == k) res++;
    }
    cout << res;
    return 0;
}