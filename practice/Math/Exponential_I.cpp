#include <bits/stdc++.h>
using namespace std;
long long MOD = 1000000007;
vector<int> toBinary(int n) {
    vector<int>a;
    while (n != 0) {
        a.push_back(n % 2);
        n = n / 2;
    }
    reverse(a.begin(), a.end());
    return a;
}

long long calculate(long long a, long long b) {
    if (b == 0)
        return 1;
    long long p = a;
    vector<int> bin = toBinary(b);
    int len = bin.size();
    for (int i = 1; i < len; i++) {
        p = (p * p) % MOD;
        if (bin[i] != 0)
            p = (p * a) % MOD;  
    }
    return p;
}


int main() {
    long long n, a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        cout << calculate(a, b) << " ";
    }
 
}