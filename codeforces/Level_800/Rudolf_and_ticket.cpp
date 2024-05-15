#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, n, m, k;
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;
        vector<int>A(n);
        vector<int>B(m);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < m; i++)
            cin >> B[i];
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (A[i] + B[j] <= k) 
                    cnt++;                  
                else    
                    break;
            }         
        }
        cout << cnt << endl;
    }
    return 0;
}