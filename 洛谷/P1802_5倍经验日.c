#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, x, lose[1005], win[1005], use[1005];
int dp[1005];

int main(){
    cin >> n >> x;
    for(int i = 1; i <= n; i++)
        scanf("%d %d %d", &lose[i], &win[i], &use[i]);
    for(int i = 1; i <= n; i++){
        for(int j = x; j >= use[i]; j--)
            dp[j] = max(dp[j] + lose[i], dp[j - use[i]] + win[i]);
        for(int j = use[i] - 1; j >= 0; j--)
            dp[j] += lose[i];
    }
    printf("%lld", 5ll * dp[x]);
    return 0;
}