#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
#define rep_rev(i, j, n) for (int i = n; i >= j ; i--)
typedef long long ll;
typedef vector<long long> vll;
ll MAX_N = 1e9 + 7;

int binSearch(int l, int r, ll s, const vll& lis) {
    int m;
    while (l < r) {
        m = (l + r) / 2;
        if (lis[m] == s)
            return m;
        else if (lis[m] > s) 
            r = m - 1;
        else
            l = m + 1;
    }
    return l;
}

void solve(const vll& a, const int& n) {
    vll lis(n + 1, MAX_N);
    lis[0] = -MAX_N;
    int index = 1;
    rep(i, 0, n) {
        if (a[i] > lis[index - 1]) {
            lis[index] = a[i];
            index++;
        }
        else {
            int k = binSearch(1, index - 1, a[i], lis);
            if (lis[k] == a[i])
                continue;
            else if (lis[k] < a[i] && lis[k + 1] > a[i])
                lis[k + 1] = a[i];~
            else if (lis[k] > a[i] && lis[k - 1] < a[i])
                lis[k] = a[i];
        }
    }
    cout << index - 1;
}

int main() {
    int n;
    cin >> n;
    vll a(n);
    rep(i, 0, n)
        cin >> a[i];
    solve(a, n);
}
