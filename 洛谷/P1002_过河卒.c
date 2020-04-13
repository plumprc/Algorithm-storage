#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
long dp[30][30];
bool flag[30][30];
int a, b, c, d;

int main(){
    cin >> a >> b >> c >> d; flag[c + 2][d + 2] = true;
    flag[c + 1][d + 4] = flag[c + 3][d + 4] = flag[c + 1][d] = flag[c + 3][d] = true;
    flag[c][d + 3] = flag[c][d + 1] = flag[c + 4][d + 3] = flag[c + 4][d + 1] = true;
    dp[2][2] = 1;
    for(int i = 2; i <= a + 2; i++){
        for(int j = 2; j <= b + 2; j++){
            dp[i][j] = max(dp[i - 1][j] + dp[i][j - 1], dp[i][j]);
            if(flag[i][j])  dp[i][j] = 0;
        }
    }
    cout << dp[a + 2][b + 2];
    return 0;
}