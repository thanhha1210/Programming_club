#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
ll n, k, sum = 0, maxSock = 0;

/*
    Objective: 
        if even number of socks & no dominant sock -> can always match all
        if even & has dominant sock -> maxPair = remain 
*/

int main() {
    cin >> n;
    rep(i, 0, n) {
        cin >> k;
        sum += k;
        maxSock = max(k, maxSock);
    }
    if (sum >= 2 * maxSock) 
        cout << sum / 2;
    else 
        cout << sum - maxSock;
}