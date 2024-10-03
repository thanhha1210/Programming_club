#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<__int128_t> vll;
typedef __int128_t ll;

vll a, res;
ll n;

void merge() {
    res.clear();
    rep(i, 0, a.size()) {
        res.push_back(a[i]);
        while (res.size() > 1 && (res[res.size() - 1] == res[res.size() - 2])) {
            long long k = res[res.size() - 1] * 2;
            res.pop_back();
            res.pop_back();
            res.push_back(k);
        }
    }
    a.swap(res);
}

int main() {
    cin >> n; 
    a.resize(n);
    rep(i, 0, n) {
        cin >> a[i]; 
    }

    while (a.size() > 1) {
        merge(); 
        if (a.size() > 1) {
            a.erase(remove(a.begin(), a.end(), *min_element(a.begin(), a.end())), a.end());
        }
    }

    cout << a[0] << endl; 
    return 0;
}
