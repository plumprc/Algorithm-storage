#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
int n, c; long long res;
int a[200005];
map<int, int > mat;

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        mat[a[i]]++; a[i] -= c;
    }
    for(int i = 0; i < n; i++){
        res += mat[a[i]];
    }
    cout << res;
    return 0;
}