#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll s, e;

ll calculate(ll a, ll b) {
    ll sum = 0;
    for (ll d = 1; d * d <= b; d++) {
        if (a % d == 0)
            s = a;
        else      
            s = (a / d + 1) * d;
        e = (b / d) * d;   

        for (ll k = s; k <= e; k+= d) {
            if (d < k / d) { 
                sum += d;
                sum += (k / d);
            }
            else if (d == k / d) {
                sum += d;
            }
        }
    }
    return sum;
}

int main() {
    ll a, b;
    cin >> a >> b;
    cout << calculate(a, b) << endl;
    return 0;
}
