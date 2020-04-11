#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;
int n, a, b, nod1, nod2, maxWidth;
int cnt[110];
struct node{
    int L, R;
}tree[110];

int depth(int pos){
    if(pos == 0) return 0;
    return 1 + max(depth(tree[pos].L), depth(tree[pos].R));
}

void width(int pos, int level, int* cnt){
    if(pos == 0) return;
    cnt[level]++;
    width(tree[pos].L, level + 1, cnt);
    width(tree[pos].R, level + 1, cnt);
}

int lca(int root, int p, int q){
    if(root == 0) return 0;
    if(root == p || root == q)
        return root;
    int left = lca(tree[root].L, p, q);
    int right = lca(tree[root].R, p, q);
    if(left != 0 && right != 0)
        return root;
    if(left == 0 && right != 0) return right;
    if(left != 0 && right == 0) return left;
    return 0;
}

int dis(int root, int pos, int d){
    if(root == 0) return 0;
    if(root == pos) return d;
    int l_dis = dis(tree[root].L, pos, d + 1);
    int r_dis = dis(tree[root].R, pos, d + 1);
    return max(l_dis, r_dis);
}

int main(){
    cin >> n;
    while(--n){
        cin >> a >> b;
        if(tree[a].L == 0)
            tree[a].L = b;
        else tree[a].R = b;
    }
    cin >> nod1 >> nod2;
    int lcanode = lca(1, nod1, nod2);
    width(1, 1, cnt);
    for(int i = 1; i < 110; i++){
        if(maxWidth < cnt[i])
            maxWidth = cnt[i];
        if(cnt[i] == 0) break;
    }
    cout << depth(1) << endl << maxWidth << endl;
    cout << 2 * dis(lcanode, nod1, 0) + dis(lcanode, nod2, 0);
    return 0;
}