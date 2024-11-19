#include <iostream>
#include <cmath>
using namespace std;

const int MAXS = 1000;

char grid[MAXS+2][MAXS+2];

void printGrid(int n, int m)            // for debugging
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++)
            cout << grid[i][j];
        cout << endl;
    }
}

bool isIntersection(int r, int c)
{
    return (grid[r][c] == 'X' && grid[r+1][c] == 'X' && grid[r-1][c] == 'X' && grid[r][c+1] == 'X' && grid[r][c-1] == 'X');
}

void setNewRowCol(int r, int c, int& newr, int& newc, int rinc, int cinc)
{
    if (grid[r+rinc][c+cinc] == 'I') {
        newr = r + 2*rinc;
        newc = c + 2*cinc;
        grid[r+rinc][c+cinc] = 'i';
    }
    else {
        newr = r + rinc;
        newc = c + cinc;
    }
}

bool nextRowCol(int currRow, int currCol, int& newr, int& newc)
{
   if (grid[currRow+1][currCol] == 'X' || grid[currRow+1][currCol] == 'I') {
        setNewRowCol(currRow, currCol, newr, newc, 1, 0);
        return false;
    }
    else if (grid[currRow-1][currCol] == 'X' || grid[currRow-1][currCol] == 'I') {
        setNewRowCol(currRow, currCol, newr, newc, -1, 0);
        return false;
    }
    else if (grid[currRow][currCol+1] == 'X' || grid[currRow][currCol+1] == 'I') {
        setNewRowCol(currRow, currCol, newr, newc, 0, 1);
        return false;
    }
    else if (grid[currRow][currCol-1] == 'X' || grid[currRow][currCol-1] == 'I') {
        setNewRowCol(currRow, currCol, newr, newc, 0, -1);
        return false;
    }
    else
        return true;
}

int floodFill(int r, int c, char ch, int nrows, int ncols)
{
    if (grid[r][c] != '.')
        return 0;
    grid[r][c] = ch;
    int count = 1;
    if (r > 0)
        count += floodFill(r-1, c, ch, nrows, ncols);
    if (r < nrows-1)
        count += floodFill(r+1, c, ch, nrows, ncols);
    if (c > 0)
        count += floodFill(r, c-1, ch, nrows, ncols);
    if (c < ncols-1)
        count += floodFill(r, c+1, ch, nrows, ncols);
    return count;
}

void findStart(int&r, int& c, char ch, int n, int m)
{
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if (grid[i][j] != ch)
                continue;
            if (grid[i-1][j] == 'e' && grid[i+1][j] == '.') {
                r = i+1;
                c = j;
                return;
            }
            if (grid[i-1][j] == '.' && grid[i+1][j] == 'e') {
                r = i-1;
                c = j;
                return;
            }
            if (grid[i][j-1] == 'e' && grid[i][j+1] == '.') {
                r = i;
                c = j+1;
                return;
            }
            if (grid[i][j-1] == '.' && grid[i][j+1] == 'e') {
                r = i;
                c = j-1;
                return;
            }
        }
    }
}

int main()
{
    int n, m;
    int arow, acol, brow, bcol;
    int lcount = 0;

    cin >> n >> m;
    for(int j=0; j<m+2; j++)
        grid[0][j] = grid[n+1][j] = '.';
    for(int i=1; i<=n; i++) {
        grid[i][0] = grid[i][m+1] = '.';
        for(int j=1; j<=m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') {
                arow = i;
                acol = j;
            }
            else if (grid[i][j] == 'B') {
                brow = i;
                bcol = j;
            }
            if (grid[i][j] != '.')
                lcount++;
        }
    }
//printGrid(n, m);
//cout << endl;
                            // find intersection points
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if (isIntersection(i,j))
                grid[i][j] = 'I';
//printGrid(n, m);
//cout << endl;
                            // flood fill in A's boundary
    int r=arow, c=acol;
//    grid[arow][acol] = 'X';  // temporary
    bool done = false;
    do {
        grid[r][c] = 'A';
        done = nextRowCol(r, c, r, c);
    } while (!done);
cout << endl;
printGrid(n, m);
cout << endl;
                            // change remaining loop characters to 'B'
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            if (grid[i][j] == 'X')
                grid[i][j] = 'B';
printGrid(n, m);
cout << endl;

// flood-fill exterior
int ecount = floodFill(0, 0, 'e', n+2, m+2);
ecount -= 2*(n+m+2);
printGrid(n, m);
cout << ecount << endl;
//cout << endl;
                            // flood=fill A area and B area
findStart(r, c, 'A', n, m);
int acount = floodFill(r, c, 'a', n+2, m+2);
findStart(r, c, 'B', n, m);
int bcount = floodFill(r, c, 'b', n+2, m+2);
//printGrid(n, m);
//cout << endl;
    cout << acount << ' ' << bcount << ' ' << n*m - lcount - ecount - acount - bcount << endl;
}
