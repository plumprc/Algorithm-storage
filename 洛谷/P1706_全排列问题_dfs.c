#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;
int m;
bool visited[10];
vector<vector<int> > res;
vector<int> tmp;

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

void dfs(){
    if(tmp.size() == m){
        res.push_back(tmp);
        return;
    }
    for(int i = 1; i <= m; i++){
        if(!visited[i]){
            tmp.push_back(i);
            visited[i] = true;
            dfs();
            tmp.pop_back();
            visited[i] = false;
        }
    }
}

int main(){
    m = read();
    dfs();
    for(int i = 0; i < res.size(); i++){
        for(int j = 0; j < m; j++)
            printf("%5d", res[i][j]);
        printf("\n");
    }
    return 0;
}