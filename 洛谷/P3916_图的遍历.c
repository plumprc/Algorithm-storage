#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v, val;
vector<int> a[100005];
int visited[100005];

void dfs(int pos, int cur){
    if(visited[pos]) return;
    visited[pos] = cur;
    for(int i = 0; i < a[pos].size(); i++)
        dfs(a[pos][i], cur);
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        a[v].push_back(u);
    }
    for(int i = n; i >= 1; i--) dfs(i, i);
    for(int i = 1; i <= n; i++)
        printf("%d ", visited[i]);
    return 0;
}