#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
int n, x, cnt = 0;
int main() {
   
    cin >> n;
    rep(i, 0, n){
        cin >> x;
        if (x % 2 != 0)
            cnt++;
    }
    cout << cnt;

}