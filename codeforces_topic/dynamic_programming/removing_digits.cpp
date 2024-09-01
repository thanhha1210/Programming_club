#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
typedef vector<long long> vll;
const ll INF = 1e9 + 7;
int n, x, cnt = 0;

int maxNum(int x) {
    int maxx = 0;
    while (x != 0) {
        maxx = max(maxx, x % 10);
        x = x / 10;
    }
    return maxx;
}

int main() {
    cin >> n;
    while (n != 0) {
        n-= maxNum(n);
        cnt++;
    }
    cout << cnt;
    return 0;

}