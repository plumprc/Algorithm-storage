#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <vector>

using namespace std;
const int MAX = 1e5 + 5;
int n, m, k, f;
struct node{
    int L, R;
    int flag;
} list[MAX];

void add(int pos, int k, int f){
    if(f == 1){
        list[k].R = list[pos].R;
        list[k].L = pos;
        list[pos].R = k;
        list[list[k].R].L = k;
    }
    else{
        list[k].R = pos;
        list[k].L = list[pos].L;
        list[pos].L = k;
        list[list[k].L].R = k;
    }
}

int main(){
    cin >> n;
    list[0].L = list[0].R = 0;
    add(0, 1, 1);
    for(int i = 2; i <= n; i++){
        cin >> k >> f;
        add(k, i, f);
    }
    cin >> m;
    while(m--){
        cin >> k;
        list[k].flag = 1;
    }
    for(int i = list[0].R; i ; i = list[i].R){
        if(list[i].flag == 0)
            cout << i << ' ';
    }
    return 0;
}