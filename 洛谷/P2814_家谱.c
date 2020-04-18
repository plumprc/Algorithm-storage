#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
map<string, string> mat;
char c; string s, fa;

string query(string s){
    while(s != mat[s])
        s = mat[s];
    return s;
}

int main(){
    while(c != '$'){
        cin >> c;
        if(c == '#'){
            cin >> fa;
            if(mat[fa].size() != 0)
                mat[fa] = query(fa);
            else mat[fa] = fa;
        }
        if(c == '+'){
            cin >> s;
            mat[s] = fa;
        }
        if(c == '?'){
            cin >> s;
            cout << s << ' ' << query(s) << endl;
        }
    }
    return 0;
}