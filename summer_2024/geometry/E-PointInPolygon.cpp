#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;
class Point {
public:
    long long x, y;
    Point() : x(0), y(0) {}
    Point(long long aX, long long aY) : x(aX), y(aY) { }

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }
    long long dot(const Point& a) const {
        return a.x * x + y * a.y;
    }
    long long cross(const Point& a) const {
        return x * a.y - y * a.x;
    }
};
Point maxx = Point(1e9 + 7, 1e9 + 7);

bool checkLine(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y))
        return true;
    return false;
}

bool checkInter(const Point& a, const Point& b, const Point& c, const Point& d) {
    Point c1 = b - a, c2 = c - a, c3 = d - a;
    return c1.cross(c2) * c3.cross(c1) >= 0;
}

bool check(const Point& a, const Point& b, const Point& c, const Point& d) {
    if (checkLine(a, b, c, d) || checkLine(c, d, a, b)) 
        return false;
    if (checkInter(a, b, c, d) && checkInter(c, d, a, b)) 
       return true;
    else
        return false;
}

bool checkBoundary(const Point& a, const Point& c, const Point& d) {
    Point p1 = c -a, p2 = d - a;
    if (p1.cross(p2) == 0 && ((a.x - c.x) * (a.x - d.x) <=0) && ((a.y - c.y) * (a.y - d.y) <=0)) {
        return true;
    }
    return false;
}

void solve(const Point& p, const int& n, const vector<Point>& pol) {
    int d = 0;
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            if (checkBoundary(p, pol[i], pol[i+1])) {
                cout << "BOUNDARY\n";
                return;
            }
            if (check(p, maxx, pol[i], pol[i + 1]))
                d++;
        }
        else {
            if (checkBoundary(p, pol[i], pol[0])) {
                cout << "BOUNDARY\n";
                return;
            }
            if (check(p, maxx, pol[i], pol[0]))
                d++;
        }
    }
    if (d % 2 != 0)
        cout << "INSIDE\n";
    else
        cout << "OUTSIDE\n";
    return;
}

int main() {
    int n, m;
    long long x, y;
    cin >> n >> m;
    vector<Point> polygon(n);
    vector<Point> point(m);
    rep(i, 0, n) {
        cin >> x >> y;
        polygon[i] = Point(x, y);
    }
    rep(i, 0, m) {
        cin >> x >> y;
        solve(Point(x, y), n, polygon);
    }
   
}