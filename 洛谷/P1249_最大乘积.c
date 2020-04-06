#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
int n, pos; bool flag;
int a[2005], b[105];

void times(int* a, int c, int n){
    int carry = 0;
    for(int i = 0; i < n; i++){
        a[i] = a[i] * c + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main(){
    cin >> n;
    int fn = n; b[pos] = 2;
    if(n == 3 || n == 4){
        cout << 1 << ' ' << n << endl << n;
        return 0;
    }
        
    while(n >= 0){
        b[pos + 1] = b[pos] + 1;
        n -= b[pos];
        pos++;
    }
    int idx = pos - 2; int los = n + b[pos - 1];
    while(los--){
        b[idx]++;
        if(idx > 0) idx--;
        else idx = pos - 2;
    }

    a[0] = b[0]; cout << b[0] << ' ';
    for(int i = 1; i < pos - 1; i++){
        times(a, b[i], 1000);
        cout << b[i] << ' ';
    }
    cout << endl;
    for(int i = 2001; i >= 0; i--){
        if(a[i] != 0) flag = true;
        if(flag) cout << a[i];
    }
    if(!flag) cout << 0;
    return 0;
}