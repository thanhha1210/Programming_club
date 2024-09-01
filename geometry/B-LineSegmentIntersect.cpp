#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;


class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double aX, double aY) : x(aX), y(aY) { }

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }
    double dot(const Point& a) const {
        return a.x * x + y * a.y;
    }
    double cross(const Point& a) const {
        return x * a.y - y * a.x;
    }
};

bool checkLine(Point a, Point b, Point c, Point d) {
    if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y))
        return true;
    return false;
}

bool check(Point a, Point b, Point c, Point d) {
    Point c1 = b - a, c2 = c - a, c3 = d - a;
    return c1.cross(c2)  * c3.cross(c1) >= 0;
}

void solve(Point a, Point b, Point c, Point d) {
    Point c1 = b - a, c2 = c - a, c3 = d - a;
    
    if (checkLine(a, b, c, d) || checkLine(c, d, a, b)) {
        cout << "NO\n";
        return;
    }
    if (check(a, b, c, d) && check(c, d, a, b)) 
        cout << "YES\n";
    else
        cout << "NO\n";
    return;
}



int main() {
    ll t;
    Point a, b, c, d;

    cin >> t;
    while (t--) {
        cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y >> d.x >> d.y;
        solve(a, b, c, d);
    }

    return 0;
}
