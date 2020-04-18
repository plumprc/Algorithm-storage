#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;
int t, n, tot, a[1000005], b[2000005];
bool flag;
struct node{
    int x, y, e;
}prog[1000005];

bool cmp(node a, node b){
    return a.e > b.e;
}

void init(int n){
    for(int i = 1; i <= n; i++)
        a[i] = i;
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

int main(){
    cin >> t;
    while(t--){
        tot = -1; flag = true;
        memset(prog, 0, sizeof(prog));
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d %d %d", &prog[i].x, &prog[i].y, &prog[i].e);
            b[++tot] = prog[i].x;
            b[++tot] = prog[i].y;
        }
        sort(b, b + tot);
        int cps = unique(b, b + tot) - b;
        for(int i = 1; i <= n; i++){
            prog[i].x = lower_bound(b, b + cps, prog[i].x) - b;
            prog[i].y = lower_bound(b, b + cps, prog[i].y) - b;
        }
        init(cps);
        sort(prog + 1, prog + 1 + n, cmp);
        for(int i = 1; i <= n; i++){
            int t1 = query(prog[i].x);
            int t2 = query(prog[i].y);
            if(prog[i].e){
                a[t1] = t2;
            }
            else{
                if(t1 == t2){
                    printf("NO\n");
                    flag = false;
                    break;
                }
            }
        }
        if(flag) printf("YES\n");
    }
    return 0;
}