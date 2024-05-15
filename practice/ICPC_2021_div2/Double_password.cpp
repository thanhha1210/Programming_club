#include <bits/stdc++.h>
using namespace std;

int main() {
    string x, y;
    int cnt;
    cin >> x >> y;
    for (int i = 0; i < 4; i++)
        if (x[i] != y[i])
            cnt++;
    cout << pow(2, cnt) << endl;
}