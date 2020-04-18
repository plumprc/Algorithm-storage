#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <unordered_map>

using namespace std;
int t, n, x;
unordered_map<int, bool> mat;

int main(){
    cin >> t;
    while(t--){
        cin >> n; mat.clear();
        while(n--){
            scanf("%d", &x);
            if(!mat[x]){
                mat[x] = 1;
                printf("%d ", x);
            }
        }
        printf("\n");
    }
    return 0;
}