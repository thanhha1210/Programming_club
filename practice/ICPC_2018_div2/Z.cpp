#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

bool check = false;
int n;

bool check1(int n) {
    while (n != 0) {
        int d = n % 10;
        n = n / 10;
        if (d == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    while (!check) {
        n++;
        if (check1(n)) {
            check = true;
        }
    }
    cout << n;
}