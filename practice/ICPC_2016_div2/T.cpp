#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
int n, m, cnt = 0, l, r, u, d;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
vvc grid;
vvb check;

bool checkValid(int x, int y) {
    return (x >= 0 && x < n && y >= 0 && y < m); 
}


void dfs(int i, int j) {
    check[i][j] = true;
    
    
    for (int dir = 0; dir < 4; dir++) {
        int ni = i + dx[dir], nj = j + dy[dir]; 
       
        if (checkValid(ni, nj) && !check[ni][nj] && (grid[ni][nj] == 'L' || grid[ni][nj] == 'C')) {
            dfs(ni, nj); 
        }
    }
}


void dfs(ll x, ll y) {
	if (grid[x][y]=='W') return;
	if (check[x][y]) return;
	check[x][y]=true;
	dfs(x+1,y);
	dfs(x-1,y);
	dfs(x,y+1);
	dfs(x,y-1);
}

int main() {
	
	ll n,m;
    cin>>n>>m;

	for (ll x=0;x<=n+1;x++) 
        for (ll y=0;y<=m+1;y++) 
            a[x][y]='W';
	for (ll x=0;x<n;x++) 
        for (ll y=0;y<m;y++) 
		cin>>a[x+1][y+1];
	
	ll ans=0;
	for (ll x=1;x<=n;x++) 
        for (ll y=1;y<=m;y++) 
		if (a[x][y]=='L'&&!seen[x][y]) {dfs(x,y);ans++;}
	
	cout<<ans<<endl;
}


int main() {
    cin >> n >> m;
    grid.assign(n, vc(m));
    check.assign(n, vb(m, false));
    rep(i, 0, n) 
        rep(j, 0, m)
            cin >> grid[i][j];

    rep(i, 0, n) {
        rep(j, 0, m) {
            if (grid[i][j] == 'L' && !check[i][j]) {
                dfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt;
}