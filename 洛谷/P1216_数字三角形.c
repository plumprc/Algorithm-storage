#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, res, a[1005], dp[1005];

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++)
            cin >> a[j];
        for(int j = i; j >= 1; j--)
            dp[j] = a[j] + max(dp[j], dp[j - 1]);
    }
    for(int i = 1; i <= n; i++)
        res = max(res, dp[i]);
    cout << res;
    return 0;
}