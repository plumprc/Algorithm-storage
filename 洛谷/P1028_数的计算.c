#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, a[1005];

int main(){
    cin >> n;
    a[0] = a[1] = 1;
    for(int i = 2; i <= n; i++){
        if((i & 1) == 0)
            a[i] = a[i - 1] + a[i / 2];
        else a[i] = a[i - 1];
    }
    cout << a[n];
    return 0;
}