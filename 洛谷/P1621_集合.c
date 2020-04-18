#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, m, p, a[100005], res;
bool b[100005];

int query(int pos){
    int root = pos, tmp;
    while(root != a[root])
        root = a[root];
    while(pos != a[pos]){
        tmp = a[pos];
        a[pos] = root;
        pos = tmp;
    }
    return root;
}

int main(){
    cin >> n >> m >> p;
    res = m - n + 1;
    for(int i = n; i <= m; i++)
        a[i] = i;
    for(int i = 2; i <= m; i++){
        if(!b[i]){
            if(i >= p){
                for(int j = i * 2; j <= m; j += i){
                    b[j] = true;
                    if(j - i >= n && query(j) != query(j - i)){
                        a[query(j)] = query(j - i);
                        res--;
                    }
                }
            }
            else{
                for(int j = i * 2; j <= m; j += i)
                    b[j] = true;
            }
        }
        
    }
    cout << res;
    return 0;
}