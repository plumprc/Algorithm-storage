#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, m, p, q, res, a[2005];
char c;

int query(int pos){
    int root = pos, tmp;
    while(root != a[root]){
        root = a[root];
    }
    while(pos != a[pos]){
        tmp = a[pos];
        a[pos] = root;
        pos = tmp;
    }
    return root;
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; i++)
        a[i] = i;
    while(m--){
        cin >> c >> p >> q;
        if(c == 'F')
            a[query(p)] = query(q);
        else{
            a[query(p + n)] = query(q);
            a[query(q + n)] = query(p);
        }
    }
    for(int i = 1; i <= n; i++){
        if(a[i] == i)
            res++;
    }
    cout << res;
    return 0;
}