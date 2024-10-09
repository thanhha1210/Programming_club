#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;

ll n, total, k;

ll f(ll x) {
    return (n * x) - ((x + 1) * x/ 2);
}

int binSearch() {
    int l = 1, r = n;
    while (l < r) {
        int x = (l + r) / 2;
        if (f(x) == k)
            return x;
        else if (f(x) > k) 
            r = x - 1;
        else
            l = x + 1;
    }
    if (f(l) < k) 
        return l + 1;
    else 
        return l;
}

int main() {
    cin >> n;
    total = n * (n - 1) / 2;
    if (total % 2 == 0)
        k = total / 2;
    else 
        k = (total + 1) / 2;
    cout << binSearch();
}