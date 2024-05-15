#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    if (a.size() == 0) {
        cout << 0 << endl;
        return 0;
    }
    else {
        int cnt = 1;
        for (int i = 1; i < a.size(); i++)
            if (a[i] != a[i - 1])
                cnt++;
        cout << cnt << endl;
        return 0;
    }
   
}