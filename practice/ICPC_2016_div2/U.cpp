#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
ll n, k, cnt = 0, k1, k2;
priority_queue<ll,vector<ll>> socks; 

int main() {
    cin >> n;
    rep(i, 0, n) {
        cin >> k;
        socks.push(k);
    }
    while (socks.size() > 2) {
        k1 = socks.top();
        socks.pop();
        k2 = socks.top();
        socks.pop();
        k3 = socks.top();
        socks.pop();

        ll d = min(k1 - k2, k3);
        cnt += d;
        if (k1 > 0) 
            socks.push(k1); 
    }
    
    cout << cnt;
}