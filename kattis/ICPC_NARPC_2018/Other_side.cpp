#include<bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

ll w, c, s, k;

int main() {
    cin >> w >> s >> c >> k;
    if (s < k) {
        cout << "YES";
    }
    else if (c + w <= k) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}