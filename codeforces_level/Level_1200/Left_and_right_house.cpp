#include <bits/stdc++.h>
using namespace std;
using namespace std;

typedef long long ll;

// Function to check if a position is valid
bool isValid(ll n, const vector<ll>& pre, ll index) {
    bool checkL = (index - pre[index]) >= ceil(index / 2.0);
    bool checkR = (pre[n] - pre[index]) >= ceil((n - index) / 2.0);
    return (checkL && checkR);
}

// Function to solve the problem
ll solve(ll n, const vector<ll>& pre) {
    ll index1 = n / 2, index2 = n / 2;
    bool check1 = false, check2 = false;
    while (index1 >= 0 || index2 <= n) {
        if (index1 >= 0 && isValid(n, pre, index1) && !check1) 
            check1 = true;
        if (index2 <= n && isValid(n, pre, index2) && !check2)
            check2 = true;
        if (check1 && check2)
            break;
        index1--; index2++;
    }

    // Determine the optimal position of the road
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        // Calculate the prefix sum
        vector<ll> pre(n + 1, 0);
        for (ll i = 0; i < n; i++) {
            if (s[i] == '1')
                pre[i + 1] = pre[i] + 1;
            else
                pre[i + 1] = pre[i];
        }

        // Call the solve function and print the result
        cout << solve(n, pre) << endl;
    }
    return 0;
}