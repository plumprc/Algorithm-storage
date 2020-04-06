#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <string>
#include <stack>

using namespace std;
string s;
int out[105]; bool flag;

int id(char c){
    switch(c){
        case '(' : return -2;
        case '[' : return -1;
        case ']' : return 1;
        case ')' : return 2;
        default  : return 0;
    }
}

void print(int a){
    if(a == 1 || a == -1)
        printf("[]");
    else if(a == 2 || a == -2)
        printf("()");
}

int main(){
    cin >> s;
    for(int i = 0; i < s.size(); i++)
        out[i] = id(s[i]);
    for(int i = 0, j = i; i < s.size(); i++){
        if(out[i] > 0){
            if(out[i] + out[j] == 0){
                out[i] = out[j] = 0;
                while(j > 0 && out[j] >= 0 && flag)
                    j--;
            }
        }
        else{
            flag = true; j = i;
        }
    }
    for(int i = 0; i < s.size(); i++){
        if(out[i] == 0) cout << s[i];
        else print(out[i]);
    }
    return 0;
}