#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
int n, ans, a[10];
vector<int*> res;

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

void dfs(int dep, int sum){
    if(dep == 10){
        if(a[0] + a[1] + a[2] + a[3] + a[4] + a[5] + a[6] + a[7] + a[8] + a[9] == n){
            ans++;
            int *b = new int[10];
            memcpy(b, a, 10 * sizeof(int));
            res.push_back(b);
        }
        return;
    }
    for(int i = 1; i <= 3; i++){
        if(sum + i > n) break;
        a[dep] = i;
        dfs(dep + 1, sum + i);
        a[dep] = 0;
    }
}

int main(){
    n = read();
    dfs(0, 0);
    cout << ans << endl;
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < 10; j++)
            cout << res[i][j] << ' ';
        cout << endl;
    }
    return 0;
}