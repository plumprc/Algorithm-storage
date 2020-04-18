#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, m, a[40005];
struct node{
    int x, y, z;
}per[100005];

bool cmp(node a, node b){
    return a.z > b.z;
}

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

bool check(int x, int y){
    return query(x) == query(y);
}

int main(){
    cin >> n >> m;
    for(int i = 1; i <= 2 * n; i++)
        a[i] = i;
    for(int i = 1; i <= m; i++)
        cin >> per[i].x >> per[i].y >> per[i].z;
    sort(per + 1, per + m + 1, cmp);
    for(int i = 1; i <= m + 1; i++){
        if(check(per[i].x, per[i].y)){
            cout << per[i].z;
            break;
        }
        else{
            a[query(per[i].x + n)] = query(per[i].y);
            a[query(per[i].y + n)] = query(per[i].x);
        }
    }
    return 0;
}