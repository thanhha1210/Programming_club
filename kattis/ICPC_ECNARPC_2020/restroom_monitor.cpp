#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<ll> vll;

ll s, n, x, n1, n2, maxn;
char c;
vll Y, N, pre1, pre2;

// Function to compute prefix counts for the given list
void computePrefix(const vll& vec, vll& pre) {
    ll j = 0, m = vec.size();
    rep(i, 0, maxn) {
        while (j < m && vec[j] == i) {
            j++;
        }
        pre[i] = j;
    }
}


bool solve() {
    ll maxY = Y.empty() ? 0 : Y.back();
    ll maxN = N.empty() ? 0 : N.back();
    maxn = min((ll)1e5 + 7, max(maxY, maxN) + 1);
   
    pre1.assign(maxn, 0);
    pre2.assign(maxn, 0);

    computePrefix(Y, pre1);
    computePrefix(N, pre2);

    rep(i, 1, maxn) {
        if (pre1[i] + pre2[i] > s * i) {
            return false;
        }
        if (pre1[i] > i) {
            return false;
        }
    }

    return true;
}

int main() {
   
    cin >> s >> n;
    rep(i, 0, n) {
        cin >> x >> c;
        if (c == 'y') Y.push_back(x);
        else N.push_back(x);
    }

   
    sort(Y.begin(), Y.end());
    sort(N.begin(), N.end());

    if (solve()) {
        cout << "Yes";
    }
    else {
        cout << "No";
    }
    return 0;
}
