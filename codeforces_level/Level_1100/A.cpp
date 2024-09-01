#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>a, int n, int k, int x) {
    sort(a.begin(), a.end());
    vector<int>prefix(n);
    prefix[0] = a[0];
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] + a[i];
    }
    int maxx = INT_MIN, sum;
    for (int i = 0; i <= k; i++) {
        int j = n - i - 1, c = 0;
        if (j <= 0)
            sum = 0;
        else {
            sum = prefix[j];
            
        } 
        maxx = max(sum, maxx);
    }

    return maxx;

}


int main() {
    long long t, k, x, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> k >> x;
        vector<int>a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << solve(a, n, k, x);
    
    }
}