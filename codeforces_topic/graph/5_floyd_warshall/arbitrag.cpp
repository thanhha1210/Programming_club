#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;



ll t, n, m, cnt = 0;
string s, s1, s2;
double r;
vvd d;
bool check;
unordered_map<string, ll> cur;

void floyd_warshall() {
    rep(k, 0, n) {
        rep(i, 0, n) { 
            rep(j, 0, n) {
                if (d[i][k] != 0.0 && d[k][j] != 0.0)
                    if (d[i][j] < d[i][k] * d[k][j]) {
                        d[i][j] =  d[i][k] * d[k][j];
                    }
                 
            }
        }
    }
}


int main() {
   
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        cur.clear();
        d.clear();
        d.assign(n , vd(n, 0.0));
        check = false;

        rep(i, 0, n) {
            cin >> s;
            cur[s] = i;
        }
        rep(i, 0, n) {
            d[i][i] = 1.0;
        }

        cin >> m;
        rep(i, 0, m) {
            cin >> s1 >> r >> s2;
            d[cur[s1]][cur[s2]] = r;
        }
     
        floyd_warshall();

        rep(i, 0, n) {
            if (d[i][i] > 1.0) {
                check = true;
                break;
            }
        }

        
        cout << "Case " << ++cnt << ": " << (check ? "Yes" : "No") << "\n";
       
    }

    return 0;
}