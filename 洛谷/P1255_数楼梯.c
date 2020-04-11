#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n; bool flag;
int a[1205], b[1205];

void pplus(int* x, int* y){
    int carry = 0;
    for(int i = 0; i < 1200; i++){
        x[i] += y[i] + carry;
        carry = x[i] / 10;
        x[i] %= 10;
    }
}

int main(){
    cin >> n;
    if(n == 0){
        cout << 0;
        return 0;
    }
    if(n == 1){
        cout << 1;
        return 0;
    }
    a[0] = 1;
    if((n & 1) == 0){
        int cnt = n / 2;
        while(cnt--){
            pplus(b, a);
            pplus(a, b);
        }
        for(int i = 1201; i >= 0; i--){
            if(a[i] != 0) flag = true;
            if(flag) cout << a[i];
        }
    }

    else{
        int cnt = n / 2;
        while(cnt--){
            pplus(b, a);
            pplus(a, b);
        }
        pplus(b, a);
        for(int i = 1201; i >= 0; i--){
            if(b[i] != 0) flag = true;
            if(flag) cout << b[i];
        }
    }
    return 0;
}