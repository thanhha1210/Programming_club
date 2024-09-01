#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

class Point {
public:
    ll x, y;
    Point() : x(0), y(0) {}
    Point(ll aX, ll aY) : x(aX), y(aY) { }

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }
    ll dot(const Point& a) const {
        return a.x * x + y * a.y;
    }
    ll cross(const Point& a) const {
        return x * a.y - y * a.x;
    }
};

ll calTriangle(Point p1, Point p2) {
    return p1.cross(p2);
}

void solve(vector<Point> v, int n) {
    ll res = 0;
    rep(i, 0, n - 1) {
        res += calTriangle(v[i], v[i + 1]);
    }
    res += calTriangle(v[n - 1], v[0]);
    cout << abs(res);
}

int main() {
    int n;
    ll x, y;
    cin >> n;
    vector<Point> v(n);
    rep(i, 0, n) {
        cin >> x >> y;
        v[i] = Point(x, y);
    }
    solve(v, n);
   
}