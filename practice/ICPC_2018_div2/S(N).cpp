#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<char> vc;
typedef vector<int> vi;
typedef long long ll;
const ll INF = 1e7;
int lMax = -INF, lMin = INF, rMax = -INF, rMin = INF, n;
int posLMax, posLMin, posRMax, posRMin;
string s;

vi d;

int main() {
    cin >> s;
    n = s.length();
 
    d.assign(n + 1, 0);
    rep(i, 0, n) {
        if (s[i] == 'B')
            d[i + 1] = d[i] - 1;
        else 
            d[i + 1] = d[i] + 1;
    }

    rep(i, 1, n + 1) {
        if (d[i] > lMax) {
            lMax = d[i];
            posLMax = i;
        } 
        if (d[i] < lMin) {
            lMin = d[i];
            posLMin = i;
        }
    }

    if (posLMax < posLMin) {
        cout << posLMax << " "<< posLMin;
    }
    else {
        cout << posLMin << " "<< posLMax;
    }
    
}
