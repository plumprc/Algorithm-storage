#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, m, t1, t2;
int a[1005];

int query(int pos){
    int t1 = pos, t2;
    while(pos != a[pos])
        pos = a[pos]; // 找祖先
    // 路径压缩
    while(t1 != a[t1]){
        t2 = a[t1];
        a[t1] = pos;
        t1 = t2;
    }
    return pos;
}

int main(){
    while(true){
        cin >> n; int res = 0;
        if(n == 0) return 0;
        cin >> m;
        for(int i = 1; i <= n; i++)
            a[i] = i;
        while(m--){
            cin >> t1 >> t2;
            a[query(t1)] = query(t2);
        }
        for(int i = 1; i <= n; i++){
            if(query(i) == i)
                res++;
        }
        cout << res - 1 << endl;
    }
    return 0;
}