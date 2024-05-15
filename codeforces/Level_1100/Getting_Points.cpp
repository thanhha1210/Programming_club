#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, P, l, t;
    int tc;
    cin >> tc;
    for (int i = 0; i < tc; i++) {
        cin >> n >> P >> l >> t;
        long long total_task = (n + 6) / 7, low = 1, high = n, ans = 0;
        while (low <= high) {
            long long mid = (high + low) / 2;
            long long get = mid * l + t * min (2 * mid, total_task);
            if (P <= get) {
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        cout << n - ans << endl;

    }
    return 0;
}