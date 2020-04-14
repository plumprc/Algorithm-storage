#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

typedef unsigned long long ull;
using namespace std;
int n, res = 1;
string s; ull base = 131;
ull a[10005];

ull hash(string s){
    int len = s.size();
    ull val = 0;
    for(int i = 0; i < len; i++)
        val = val * base + (ull)s[i];
    return val;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> s;
        a[i] = hash(s);
    }
    sort(a, a + n);
    for(int i = 0; i < n - 1; i++){
        if(a[i] != a[i + 1])
            res++;
    }
    cout << res;
    return 0;
}