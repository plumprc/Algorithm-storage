#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;
int n, num, t, res, a[10005], f[10005];
vector<int> edge[10005];

int dfs(int pos){
    if(f[pos]) return f[pos];
    for(int i = 0; i < edge[pos].size(); i++)
        f[pos] = max(f[pos], dfs(edge[pos][i]));
    f[pos] += a[pos];
    return f[pos];
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d %d", &num, &a[i]);
        while(scanf("%d", &t) && t)
            edge[t].push_back(num);
    }
    for(int i = 1; i <= n; i++)
        res = max(res, dfs(i));
    cout << res;
    return 0;
}