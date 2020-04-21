#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n, num, u, res, t[10005], f[10005], ind[10005];
vector<int> edge[10005];
queue<int> q;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &num, &t[i]);
        while(scanf("%d", &u) && u){
            edge[u].push_back(num);
            ind[num]++;
        }
    }
    // 初始化
    for(int i = 1; i <= n; i++){
        if(ind[i] == 0){
            q.push(i);
            f[i] = t[i];
        }
    }
    while(!q.empty()){
        int rhs = q.front();
        q.pop();
        for(int i = 0; i < edge[rhs].size(); i++){
            int u = edge[rhs][i];
            ind[u]--;
            if(ind[u] == 0) q.push(u);
            f[u] = max(f[u], f[rhs] + t[u]);
        }
    }
    for(int i = 1; i <= n; i++)
        res = max(res, f[i]);
    cout << res;
    return 0;
}