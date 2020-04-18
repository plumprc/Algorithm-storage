#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#define mod 100007

using namespace std;
int n, T, num, maxx;
vector<int> Hash[100007];

inline int read() {
    int w = 1, q = 0;
    char ch = ' ';
    while (ch != '-' && (ch < '0' || ch > '9')) ch = getchar();
    if (ch == '-') w = -1, ch = getchar();
    while (ch >= '0' && ch <= '9') q = q * 10 + ch - '0', ch = getchar();
    return w * q;
}

bool check(int val){
    int pos = (val % mod + mod) % mod;
    maxx = max(maxx, pos);
    for(int i = 0; i < Hash[pos].size(); i++){
        if(Hash[pos][i] == val)
            return true;
    }
    Hash[pos].push_back(val);
    return false;
}

int main(){
    T = read();
    while(T--){
        n = read();
        for(int i = 0; i <= maxx; i++)
            Hash[i].clear();
        maxx = 0;
        for(int i = 1; i <= n; i++){
            num = read();
            if(!check(num))
                printf("%d ", num);
        }
        printf("\n");
    }
    return 0;
}