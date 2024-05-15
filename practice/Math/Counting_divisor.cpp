#include <bits/stdc++.h>
using namespace std;
int countDivisor(int x) {
    int cnt = 0;
    for (int i = 1; i <= trunc(sqrt(x)); i++) {
        if (x % i == 0)
            cnt += 2;
    }
    if (trunc(sqrt(x)) * trunc(sqrt(x)) == x)
        cnt-= 1;
    return cnt;
}

int main() {
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        cout << countDivisor(x) << endl;
    }
}