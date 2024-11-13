#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;

const ll N = 2e16 + 26;

vll e(N), ne(N), h(N);
vll e2(N), ne2(N), h2(N);
vll d(N), dist(N), dd(N);
vll q(N), p(N), p2(N), p3(N), p4(N);
ll idx, idx2, n, m, tt = -1, hh = 0;

void add1(ll a, ll b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
void add2(ll a, ll b) {
    e2[idx] = b, ne2[idx] = h2[a], h[a] = idx2++;
}

void toposort() {
    rep(i, 1, n + 1) {
        if (d[i] == 0) q[++tt] = i;
    }
    while (hh <= tt) {
        ll head = q[hh++];
        if (h[head] == -1) continue;
        int j = e[h[head]];
        d[j]--;
        if (d[j] == 0) q[++tt] = j;
    }
}

int main() {
    cin >> n;
    h.assign(N, -1);
    h2.assign(N, -1);
    rep(i, 1, n + 1) {
        ll x;
        cin >> x;
        if (i == x) p2[i] = 1;
        add1(i, x);
        add2(x, i);
        d[x]++;
    }
    toposort();

    ll cott = 0;
    rep(i, 0, n * 2) {
        if (q[i] != 0) p3[q[i]]++;
    }
    rep(i, 1, n + 1) {
        if (p3[i]) cott++;
    }
    ll ccoo = n - cott;
    if (tt == -1) ccoo = n;

    ll sum = ccoo;
    rep(i, n + 1, 2 * n + 1) {
        queue<ll> qq;
        qq.push(i);
        ll maxa = 0;
        while (qq.size()) {
            ll x = qq.front();
            qq.pop();
            if (h2[x] == -1) continue;
            for(int j = h2[x]; j != -1; j = ne2[j]) {
                ll k = e2[j];
                if (x == k) break;
                if (p3[k] == 0) break;
                dist[k] = max(dist[k], dist[x] + 1);
                maxa = max(dist[k], maxa);
                qq.push(k);
            }
        }
        sum += maxa;
    }
    cout << sum << '\n';
    return 0;
}
