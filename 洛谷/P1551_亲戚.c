#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, m, p, t1, t2;
int a[5005];

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
    cin >> n >> m >> p;
    for(int i = 1; i <= n; i++)
        a[i] = i; // 初始每个人自成一个集合
    while(m--){
        cin >> t1 >> t2;
        a[query(t1)] = query(t2);
    }
    while(p--){
        cin >> t1 >> t2;
        if(query(t1) == query(t2))
            cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}