#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <climits>
#include <stack>

using namespace std;
int q, n, pos;
int a[100005], b[100005];
stack<int> s;

int main(){
    cin >> q; pos = 0;
    while(q--){
        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];
        for(int i = 0; i < n; i++)
            cin >> b[i];
        for(int i = 0; i < n; i++){
            s.push(a[i]);
            while(s.top() == b[pos]){
                s.pop(); pos++;
                if(s.empty())
                    break;
            }
        }
        cout << (s.empty()? "Yes" : "No") << endl;
        while(!s.empty())
            s.pop();
    }
    return 0;
}