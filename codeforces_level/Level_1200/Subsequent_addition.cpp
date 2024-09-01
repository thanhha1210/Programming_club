#include <bits/stdc++.h>
using namespace std;

bool check(const vector<int>& a, const int& n) {
    if (n <= 0)
        return false;
    if (a[0] != 1) 
        return false;
    long long sum = 1;
    int i = 1;
    while (i < n) {
        if (sum < a[i])
            return false;
        else
            sum += a[i];
        i++; 
    }
    return true;
}
int main() {
    long long t, n;
    cin >> t;
    for (int d = 0; d < t; d++) {
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];
        sort(a.begin(), a.end());
        cout << (check(a,n) ? "YES" : "NO") << endl;
    }
}