#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>

using namespace std;
int n, pos; bool flag;
int a[500];

void times(int* a, int c){
    int carry = 0;
    for(int i = 0; i < 500; i++){
        a[i] = a[i] * c + carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }
}

int main(){
    cin >> n; a[0] = 1;
    cout << ceil(n * log10(2)) << endl;
    while(n){
        if(n >= 20){
            times(a, 1048576);
            n -= 20;
        }
        else if(n >= 10){
            times(a, 1024);
            n -= 10;
        }
        else if(n >= 5){
            times(a, 32);
            n -= 5;
        }
        else{
            times(a, 2);
            n--;
        }
    }
        
    for(int i = 499; i >= 1; i--){
        if(i != 499 && (i+1) % 50 == 0) printf("\n%d", a[i]);
        else cout << a[i];
    }
    cout << a[0] - 1;
    return 0;
}