#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n, m, u, v;
vector<int> a[100005];
bool visited[100005];
queue<int> q;

void dfs(int pos, int cur){
    visited[pos] = true;
    cout << pos << ' ';
    if(cur == n) return;
    for(int i = 0; i < a[pos].size(); i++){
        if(!visited[a[pos][i]])
            dfs(a[pos][i], cur + 1);
    }
}

void bfs(int pos){
    memset(visited, false, sizeof(visited));
    visited[pos] = true;
    q.push(pos);
    while(!q.empty()){
        int v = q.front();
        cout << v << ' ';
        q.pop();
        for(int i = 0; i < a[v].size(); i++){
            if(!visited[a[v][i]]){
                q.push(a[v][i]);
                visited[a[v][i]] = true;
            }
        }
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        a[u].push_back(v);
    }
    for(int i = 1; i <= n; i++)
        sort(a[i].begin(), a[i].end());
    dfs(1, 0);
    printf("\n");
    bfs(1);
    return 0;
}