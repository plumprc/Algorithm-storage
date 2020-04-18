#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int T, m, t[10005], value[10005];
int dp[100005];

int main(){
    cin >> T >> m;
    for(int i = 1; i <= m; i++)
        scanf("%d %d", &t[i], &value[i]);
    for(int i = 1; i <= m; i++){
        for(int j = T; j >= t[i]; j--)
            dp[j] = max(dp[j], dp[j - t[i]] + value[i]);
    }
    cout << dp[T];
    return 0;
}