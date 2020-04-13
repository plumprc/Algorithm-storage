#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, a[30];

int main(){
    cin >> n;
    a[0] = a[1] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            a[i] += a[j] * a[i - j - 1];
        }
    }
    cout << a[n];
    return 0;
}