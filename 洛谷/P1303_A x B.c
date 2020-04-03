#include <iostream>
#include <string>

using namespace std;
int a[2005], b[2005], c[4005];
string s1, s2; int len1, len2; bool flag;

void times(int* a, int* b, int*c, int n){
    int carry = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i+j] += a[i] * b[j] + carry;
            carry = c[i+j] / 10;
            c[i+j] %= 10;
        }
    }
}

int main(){
    cin >> s1 >> s2;
    len1 = s1.size(); len2 = s2.size();
    for(int i = 0; i < len1; i++)
        a[i] = s1[len1 - i - 1] - '0';
    for(int i = 0; i < len2; i++)
        b[i] = s2[len1 - i - 1] - '0';
    times(a, b, c, 2000);
    for(int i = 4001; i >= 0; i--){
        if(c[i] != 0) flag = true;
        if(flag) cout << c[i];
    }
    if(!flag) cout << 0;
    return 0;
}