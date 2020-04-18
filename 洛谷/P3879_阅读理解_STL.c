#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>

using namespace std;
int n, m, t; string s;
unordered_map<string, vector<int> > mat;

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> m;
        while(m--){
            cin >> s;
            mat[s].push_back(i);
        }
    }
    cin >> t;
    while(t--){
        cin >> s;
        if(mat[s].size() > 0)
            cout << mat[s][0];
        for(int i = 1; i < mat[s].size(); i++){
            if(mat[s][i] != mat[s][i - 1])
                cout << ' ' << mat[s][i];
        }
        printf("\n");
    }
    return 0;
}