#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <cstring>

using namespace std;
int n, t, b, pos, cnt;
int a[2605];

void times(int* a, int c){
    int carry = 0;
    for(int i = 0; i < 2600; i++){
        a[i] = a[i] * c + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main(){
    cin >> n;
    while(n--){
        memset(a, 0, sizeof(a)); a[0] = 1; cnt = 0;
        cin >> t >> b;
        for(int i = 2; i <= t; i++)
            times(a, i);
        for(int i = 2600; i >= 0; i--){
            if(a[i] != 0){
                pos = i;
                break;
            }
        }
        for(int i = pos; i >= 0; i--){
            if(a[i] == b)
                cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}