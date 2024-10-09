#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)

typedef vector<char> vc;
typedef vector<vector<char>> vvc;
int n;
vvc grid;
unordered_map<char, int> temp;
bool checkChar(char x) {
    if (n <= 10)
        return (('0' <= x) && (x < '0' + n));
    else 
        return ((('0' <= x) && (x <= '9')) ||(('A' <= x) && (x < 'A' + (n - 10))));
}
bool check1() {
    rep(i, 0, n) {
        temp.clear();
        rep(j, 0, n) {
            if (!checkChar(grid[i][j]) || temp.find(grid[i][j]) != temp.end()) {
                return false;
            }
            temp[grid[i][j]] = 1;
        }
    }
    rep(j, 0, n) {
        temp.clear();
        rep(i, 0, n) {
            if (!checkChar(grid[i][j]) || temp.find(grid[i][j]) != temp.end()) {
                return false;
            }
            temp[grid[i][j]] = 1;
        }
    }
    return true;
}

bool check2() {
    rep(i, 1, n) {
        if (grid[i][0] <= grid[i - 1][0]) 
            return false;
    }
    rep(j, 1, n) {
        if (grid[0][j] <= grid[0][j - 1]) 
            return false;
    }
    return true;
}


int main() {
    while (cin >> n) {
        grid.clear();
        grid.assign(n, vc(n));
        rep(i, 0, n) {
            rep(j, 0, n) {
                cin >> grid[i][j];
            }
        }

        if (!check1()) {
            cout << "No\n";
        }
        else if (!check2()) {
            cout << "Not Reduced\n";
        }
        else {
            cout << "Reduced\n";
        }
    }
   
}