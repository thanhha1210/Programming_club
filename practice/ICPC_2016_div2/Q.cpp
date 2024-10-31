#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long>vll;
typedef multiset<long long> sll;

ll n, k, sum = 0;
sll bag;
vll a, res, prefix;

int main() {
    cin >> n >> k;
    a.resize(n);
    prefix.resize(n);
    rep(i, 0, n) {
        cin >> a[i];
        if (i < k)
            bag.insert(a[i]);
    }

    rep(i, k, n) {
        auto it = bag.begin();
        res.emplace_back(*it);
        bag.erase(it);
        bag.insert(a[i]);
    }

    while (bag.size() != 0) {
        auto it = bag.begin();
        res.emplace_back(*it);
        bag.erase(it);
    }

    prefix[0]= res[0];
    rep(i, 1, n) {
        prefix[i] = prefix[i - 1] + res[i];
    }
    rep(i, 0, n) {
        sum += prefix[i];
    }

    cout << sum;

}
