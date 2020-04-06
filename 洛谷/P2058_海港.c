#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <queue>
#include <map>

using namespace std;
int n, t, k, a, cnt;
int mat[1000005];
struct node{
    int s, t;
};
queue<node> ship; node h;

int main(){
    cin >> n;
    while(n--){
        cin >> t >> k;
        while(!ship.empty()){
            h = ship.front();
            if(h.t + 86400 <= t){
                mat[h.s]--;
                if(mat[h.s] == 0)
                    cnt--;
                ship.pop();
                continue;
            }
            break;
        }
        while(k--){
            cin >> a;
            h.s = a, h.t = t;
            ship.push(h);
            mat[a]++;
            if(mat[a] == 1)
                cnt++;
        }
        cout << cnt << endl;
    }
    return 0;
}