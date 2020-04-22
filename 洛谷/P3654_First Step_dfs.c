#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
int n, m, r, res, dx[2] = {0, 1}, dy[2] = {1, 0};
char mat[105][105];

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

void dfs(int x, int y, int i, int j){
    if(j > r){
        res++;
        return;
    }
    if(mat[x][y] != '.' || x < 0 || y < 0 || x >= n || y >= m)
        return;
    dfs(x + dx[i], y + dy[i], i, j + 1);
}

int main(){
    n = read(); m = read(); r = read();
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> mat[i][j];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '.'){
                dfs(i, j, 0, 1);
                dfs(i, j, 1, 1);
            }
        }
    }
    if(r == 1) res /= 2;
    cout << res;
    return 0;
}