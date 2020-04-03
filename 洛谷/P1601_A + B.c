#include <iostream>
#include <string>

using namespace std;
int a[2005], b[2005];
string s1, s2; int len1, len2; bool flag;

void pplus(int* a, int* b, int n){
    int carry = 0;
    for(int i = 0; i < n; i++){
        b[i] += a[i] + carry;
        carry = b[i] / 10;
        b[i] %= 10;
    }
}

int main(){
    cin >> s1 >> s2;
    len1 = s1.size(); len2 = s2.size();
    for(int i = 0; i < len1; i++)
        a[i] = s1[len1 - i - 1] - '0';
    for(int i = 0; i < len2; i++)
        b[i] = s2[len1 - i - 1] - '0';
    pplus(a, b, 2000);
    for(int i = 2001; i >= 0; i--){
        if(b[i] != 0) flag = true;
        if(flag) cout << b[i];
    }
    if(!flag) cout << 0;
    return 0;
}