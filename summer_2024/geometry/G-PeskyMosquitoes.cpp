#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)

class Point {
public:
    double x, y;
    Point() : x(0), y(0) {}
    Point(double aX, double aY) : x(aX), y(aY) { }

    Point operator*(const double k) const {
        return Point (x * k, y * k);
    }
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
    double squareDistance(const Point& a) const {
        return (x - a.x) * (x - a.x) + (y - a.y) * (y - a.y);
    }
};

int findNum(Point o, vector<Point> points, double dia) {
    int res = 0;
    rep(i, 0, points.size()) {
        if (o.squareDistance(points[i]) <= dia * dia / 4.0) 
            res++;
    }
    return res;
}

// max number can cover if point a, b is on the edge
int findMax(Point a, Point b, vector<Point> points, double dia) {  
    // d^2 + R^2 - 2dR cos(alpha) = R^2
    double rad = dia / 2;
    double d = a.squareDistance(b);

    Point v = a - b; // vector ab
    Point m = Point(-v.y, v.x); // perpendicular vector ab
    Point mid = Point((a.x + b.x)/2, (a.y + b.y)/2);
    double h = rad * rad - (sqrt(d)/2) * ((sqrt(d)/2)); 
    Point o = m * sqrt(h);
    Point o2 = mid * 2- o;
    return max(findNum(o, points, dia), findNum(o2, points, dia));

}


void solve(vector<Point> points, int n, double d) {
    int maxx = 1, temp;
    rep(i, 0, points.size()) {
        rep(j, i + 1, points.size()) {
            if (points[i].squareDistance(points[j]) > d * d) {
                continue;
            }
            temp = findMax(points[i], points[j], points, d);
            maxx = max(maxx, temp);
        }
    }
    cout << maxx << '\n';
}

int main() {
    int n, t;
    double x, y, d;
    cin >> t;
    while (t--) {
        cin >> n >> d;
        vector<Point> points(n);
        rep(i, 0, n) {
            cin >> x >> y;
            points[i] = Point(x, y);
        }
        solve(points, n, d);
    }
    
}