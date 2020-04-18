#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;
int n, T, cps;
struct node{
    int val, id;
    inline bool operator<(const node &t) const{
        return val < t.val || val == t.val && id < t.id;
    }
    inline bool operator==(const node &t) const{
        return val == t.val;
    }
}a[500005];

inline bool cmp(node a, node b){
    return a.id < b.id;
}

int main(){
    cin >> T;
    while(T--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i].val);
            a[i].id = i;
        }
        sort(a + 1, a + 1 + n);
        cps = unique(a + 1, a + 1 + n) - a - 1;
        sort(a + 1, a + 1 + cps, cmp);
        for(int i = 1; i <= cps; i++)
            printf("%d ", a[i].val);
        printf("\n");
    }
    return 0;
}