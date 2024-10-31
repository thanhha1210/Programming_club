#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)


class PointS {
public:
    int x, y, id, s;
    PointS() : x(0), y(0), id(0), s(0) {}
    PointS(int aX, int aY, int aId, int aS) : x(aX), y(aY), id(aId), s(aS) {}
};

class Point {
public:
    int x, y;
    Point() : x(0), y(0) {}
    Point(int aX, int aY) : x(aX), y(aY) { }

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }
    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }
    int dot(const Point& a) const {
        return a.x * x + y * a.y;
    }
    int cross(const Point& a) const {
        return x * a.y - y * a.x;
    }
};

class Segment {
public:
    Point p1, p2;
    Segment() : p1(0, 0), p2(0, 0) {}
    Segment(int a, int b, int c, int d) : p1(a, b), p2(c, d) {}
};

struct CompareY { 
    bool operator()(PointS a, PointS b) const
    { 
        return (a.y < b.y) || (a.y == b.y && a.s > b.s) ; 
    } 
};

bool checkLine(Point& a, Point& b, Point& c, Point& d) {
    if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y))
        return true;
    return false;
}

bool checkInter(Point& a, Point& b, Point& c, Point& d) {
    Point c1 = b - a, c2 = c - a, c3 = d - a;
    return c1.cross(c2) * c3.cross(c1) >= 0;
}

bool check(Point& a, Point& b, Point& c, Point& d) {
    if (checkLine(a, b, c, d) || checkLine(c, d, a, b)) 
        return false;
    if (checkInter(a, b, c, d) && checkInter(c, d, a, b)) 
       return true;
    else
        return false;
}

void solve(vector<PointS>& a, vector<Segment>& segments) {
    set<PointS, CompareY> s;
    for (int i = 0; i < a.size(); i++) {
        PointS p = a[i];
        Segment pC = segments[p.id];
        
        if (p.s == 1) {     // if it is a start point -> put into set s, compare with upper & lower
            s.insert(p);
            auto it = s.find(p);
            if(it != s.begin()) {
                auto previous = prev(it);
                Segment pL = segments[previous->id]; 
                if (check(pC.p1, pC.p2, pL.p1, pL.p2) && (p.id != previous->id)) {
                    cout << "YES\n" << p.id << " " << previous->id;
                    return;
                }
            }
           
            auto nextEl = next(it); // [ A ] s.begin() -> 0th. ith + 1 ~ nth s.end()
            if (nextEl != s.end()) { // s.end() is element after last element
                Segment pU = segments[nextEl->id];
                if (check(pC.p1, pC.p2, pU.p1, pU.p2) && (p.id != nextEl->id)) {
                    cout << "YES\n" << p.id << " " << nextEl->id;
                    return;
                }
            }
        }

        else {      // Find upper and lower of that high, pop the point out
            auto it = s.find(p);
            auto nextEl = next(it);
            if (it != s.begin() && nextEl != s.end()) {
                auto previous = prev(it);
                Segment pL = segments[previous->id];
                Segment pU = segments[nextEl->id];
                if (check(pL.p1, pL.p2, pU.p1, pU.p2) && (previous->id != nextEl->id)) {
                    cout << "YES\n" << previous->id << " " << (nextEl->id);
                    return;
                }
            }
            PointS pp = PointS(pC.p1.x, pC.p1.y, p.id, 1); 
            auto itP = s.find(pp);
            s.erase(itP);
        }
    }
    cout << "NO";
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, a, b, c, d;
    cin >> n;
    vector<PointS> v(2 * n);
    vector<Segment> segments(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        PointS p1 = PointS(a, b, i, 1); 
        PointS p2 = PointS(c, d, i, -1);
        v[2 * (i - 1)] = PointS(a, b, i, 1);     // Start point
        v[2 * (i - 1) + 1] = PointS(c, d, i, -1);    // End point  
        segments[i] = Segment(a, b, c, d);
    }

    sort(v.begin(), v.end(), [](PointS& a, PointS& b) {
        return (a.x < b.x || (a.x == b.x && a.s > b.s));
    });

    solve(v, segments);
    return 0;
}
