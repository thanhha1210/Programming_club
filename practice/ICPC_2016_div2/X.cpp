#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)

int main(int argc, char *argv[]) {
    vector<int> v(6) ;
    for (int i=0; i<6; i++)
        cin >> v[i] ;
    int a = v[0]*v[1] + v[2]*v[3] + v[4]*v[5] ;
    int s = (int)sqrt(a) ;
    int success = 0 ;
    if (s * s == a) {
        int s2 = -1 ;
        for (int i=0; i<6; i += 2)
            if (v[i] == s || v[i+1] == s) {
                swap(v[4], v[i]) ;
                swap(v[5], v[i+1]) ;
                s2 = 2 * s - v[4] - v[5] ;
            }
        if (s2 > 0) {
            if (((v[0] == s || v[1] == s) && (v[2] == s || v[3] == s)) ||
                ((v[0] == s2 || v[1] == s2) && (v[2] == s2 || v[3] == s2)))
                success++ ;
        }
    }
    cout << (success ? "YES" : "NO") << endl ;
}

/*
int x[2], y[2], z[2], k1, k2;

bool check1() {
    bool check = false;
    int temp[2];
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            if (x[i] == y[j]) {
                temp[0] = x[i];
                temp[1] = x[1 - i] + y[1 - j];
                check = true;
                //cout << "x, y: " << temp[0] << " " << temp[1] << '\n';
                break;
            }
        }
    }
    if (!check) return false;
    rep(i, 0, 2) {
        rep(j, 0 , 2) {
            if (temp[i] == z[j]) {
                k1 = temp[i];
                k2 = temp[1 - i] + z[1 - j];
                //cout << "temp, z: " << k1 << " " << k2 << '\n';
                if (k1 == k2)
                    return true;
            }
        }
    }
    return false;
}
bool check2() {
    bool check = false;
    int temp[2];
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            if (x[i] == z[j]) {
                temp[0] = x[i];
                temp[1] = x[1 - i] + z[1 - j];
                check = true;
                //cout << "x, z: " << temp[0] << " " << temp[1] << '\n';
                break;
            }
        }
    }
    if (!check) return false;
    rep(i, 0, 2) {
        rep(j, 0 , 2) {
            if (temp[i] == y[j]) {
                k1 = temp[i];
                k2 = temp[1 - i] + y[1 - j];
                //cout << "temp, y: " << k1 << " " << k2 << '\n';
                if (k1 == k2)
                    return true;
            }
        }
    }
    return false;
}

bool check3() {
    bool check = false;
    int temp[2];
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            if (y[i] == z[j]) {
                temp[0] = y[i];
                temp[1] = y[1 - i] + z[1 - j];
                check = true;
                //cout << "y, z: " << temp[0] << " " << temp[1] << '\n';
                break;
            }
        }
    }
    if (!check) return false;
    rep(i, 0, 2) {
        rep(j, 0 , 2) {
            if (temp[i] == x[j]) {
                k1 = temp[i];
                k2 = temp[1 - i] + x[1 - j];
                //cout << "temp, z: " << i << " " << j << " " << k1 << " " << k2 << '\n';
                if (k1 == k2)
                    return true;
            }
        }
    }
    return false;
}
bool check4() {
    rep(i, 0, 2) {
        rep(j, 0, 2) {
            rep(k, 0, 2) {
                if (x[i] == y[j] && y[j] == z[k]) {
                    k1 = x[i];
                    k2 = x[1 - i] + y[1 - j] + z[1 - k];
                    if (k1 == k2)
                        return true;
                }
            }
        }
    }
    return false;
}

int main() {
    cin >> x[0] >> x[1];
    cin >> y[0] >> y[1];
    cin >> z[0] >> z[1];
    if (check1() || check2() || check3() || check4()) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}
*/
