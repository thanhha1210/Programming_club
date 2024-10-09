#include<bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)
typedef long long ll;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef vector<vector<ll>> vvll;
typedef pair<long long, long long> pll;
typedef vector<pair<long long, long long>> vpll;

char c;
ll n, col, row;
vpll b, num;    // b - bulb, num - number cell
vvll d;
vvc grid;
bool check = true;

void lightUp(ll x, ll y) {
    for (int i = x - 1; i >= 0; i--) {
        if (grid[i][y] == '.') 
            d[i][y]++;
        else if (grid[i][y] == '?') {
            check = false; 
            break;         
        }
        else 
            break;          
    }
}
void lightDown(ll x, ll y) {
    rep(i, x + 1, n) {
        if (grid[i][y] == '.') 
            d[i][y]++;
        else if (grid[i][y] == '?') {
            check = false;  
            break;
        }
        else 
            break;
    }
}

void lightLeft(ll x, ll y) {
    for (int i = y - 1; i >= 0; i--) {
        if (grid[x][i] == '.') 
            d[x][i]++;
        else if (grid[x][i] == '?') { 
            check = false;  
            break;
        }
        else 
            break;
    }
}

void lightRight(ll x, ll y) {
    rep(i, y + 1, n) {
        if (grid[x][i] == '.') 
            d[x][i]++;
        else if (grid[x][i] == '?') {
            check = false;  
            break;
        } 
        else 
            break;
    }
}

bool check1() {
    d.assign(n, vll(n, 0)); 
    rep(i, 0, b.size()) {    
        lightUp(b[i].first, b[i].second);
        lightDown(b[i].first, b[i].second);
        lightLeft(b[i].first, b[i].second);
        lightRight(b[i].first, b[i].second);
    }
    
  
    rep(i, 0, n) {
        rep(j, 0, n) {
            if (grid[i][j] == '.' && d[i][j] < 1)
                return false;  
        }
    }
    return true;
}

int count(ll x, ll y) {
    int cnt = 0;
    if (x - 1 >= 0 && grid[x - 1][y] == '?')
        cnt++;
    if (x + 1 < n && grid[x + 1][y] == '?')
        cnt++;
    if (y - 1 >= 0 && grid[x][y - 1] == '?')
        cnt++;
    if (y + 1 < n && grid[x][y + 1] == '?')
        cnt++;
    return cnt;
}

bool check2() {
    rep(i, 0, num.size()) {
        row = num[i].first;
        col = num[i].second;
        
        if (grid[row][col] != 'X') {
            int cnt = count(row, col); 
            if (char(cnt + '0') != grid[row][col])
                return false;  
        }
    }
    return true;
}

int main() {
    cin >> n;
    grid.assign(n, vc(n));
   
    rep(i, 0, n) {
        rep(j, 0, n) {
            cin >> c;
            grid[i][j] = c;
            if (grid[i][j] == '.') {
                continue;
            }
            else if (grid[i][j] == '?') {
                b.push_back({i, j}); 
            }
            else {
                num.push_back({i, j}); 
            }
        }
    }
    
    if (check1() && check2() && check) {
        cout << 1 << '\n'; 
    }
    else {
        cout << 0 << '\n';  
    }
}
