#include <bits/stdc++.h>
using namespace std;

int countMatch(long long n, long long m, long long k, vector<long long>& a, vector<long long>& b) {
    int i = 0, j = 0, cnt = 0;
    while (i < n && j < m) {
        if (b[j]- k <= a[i] && a[i] <= b[j] + k) {
            i++; j++; cnt++;
        }
        else if (b[j] + k < a[i])   // actual size is too small, then increase actual size
            j++;
        else if (b[j] - k > a[i])   // actual size now is too big, then increase desired size
            i++;        
    }
    return cnt;
}

int main() {
    long long n, m, k;
    cin >> n >> m >> k;         // n = # desired apartment size, m = # actually apartment size, k = possible range
    vector <long long> a(n);
    vector <long long> b(m);
    
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    cout << countMatch(n, m, k, a, b) << endl;
    return 0;
}

