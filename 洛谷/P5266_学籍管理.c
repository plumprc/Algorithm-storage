#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

using namespace std;
int n, a, b; string s;
map<string, int> mat;

int main(){
    cin >> n;
    while(n--){
        cin >> a;
        if(a == 1){
            cin >> s >> b;
            mat[s] = b;
            cout << "OK\n";
        }
        else if(a == 2){
            cin >> s;
            if(mat[s] == 0){
                mat.erase(s);
                cout << "Not found\n";
            }
                
            else cout << mat[s] << endl;
        }
        else if(a == 3){
            cin >> s;
            if(mat[s] == 0){
                mat.erase(s);
                cout << "Not found\n";
            }
            else {
                mat.erase(s);
                cout << "Deleted successfully\n";
            }
        }
        else{
            cout << mat.size() << endl;
        }
    }
    return 0;
}