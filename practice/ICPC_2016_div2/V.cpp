#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<long long, long long> pll;
typedef set<pair<long long, long long>> spll;
spll neg, pos;
ll n, k, x, y, dist = 0, num, temp;

void checkNeg() {
    while (!neg.empty()) {
        auto it = neg.rbegin();
        
        num = ceil ((1.0 *  it -> second) / k); // number of time to finish at x
        temp = (num * k) - it->second;
        dist += (2 * num)  * (it -> first);
        neg.erase(prev(neg.end()));

        while (temp > 0 && !neg.empty()) {
            it = neg.rbegin();
            ll k = min(temp, it->second);
            temp -= k;

            pll subIt = {it->first, it->second - k};
            neg.erase(prev(neg.end()));
            neg.insert(subIt);
            it = neg.rbegin();

            if (it->second == 0) {
                neg.erase(prev(neg.end()));
            }
        }

    }
}


void checkPos() {
    
    while (!pos.empty()) {
        auto it = pos.rbegin();
    
        num = ceil ((1.0 *  it -> second) / k); // number of time to finish at x
        temp = (num * k) - it->second;
        dist += (2 * num)  * (it -> first);
        pos.erase(prev(pos.end()));

        while (temp > 0 && !pos.empty()) {
            it = pos.rbegin();
            ll k = min(temp, it->second);
            temp -= k; 

            pll subIt = {it->first, it->second - k};
            pos.erase(prev(pos.end()));
            pos.insert(subIt);
            it = pos.rbegin();

            if (it->second == 0) {
                pos.erase(prev(pos.end()));
            }
        }

    }
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        if (x < 0)
            neg.insert({-x, y});  
        else 
            pos.insert({x, y});
    }
    checkNeg();
    checkPos();
    cout << dist << endl;

    return 0;
}
