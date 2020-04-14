#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
int n, res; string a, b;
map<int, int> mat[100005];

int main(){
    cin >> n;
    while(n--){
        cin >> a >> b;
        int A = a[0] * 26 + a[1];
        int B = b[0] * 26 + b[1];
        res += mat[B][A];
        if(A == B)
            res -= mat[A][A];
        mat[A][B]++;
    }
    cout << res;
    return 0;
}