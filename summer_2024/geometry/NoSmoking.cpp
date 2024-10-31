#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for(int i = j; i < n; i++)
typedef long long ll;

class PointS {
public: 
    double x, y;
    int id, s;
    PointS(double aX, double aY, int aId, int aS) : x(aX), y(aY), id(aId), s(aS){}
};

class Segment {
public:
    double x1, y1, x2, y2;
    Segment(double a, double b, double c, double d) : x1(a), y1(b), x2(c), y2(d) { }
}
// typedef tuple<double, int, double, int> PointS;
// typedef array<double, 5> BigPoint; //p[1];

// bool operator< (PointS& a, PointS & b) {
//     auto &[x1, y1, id, s] = a;
//     auto &[x2, y2, id2, s2] = b;
//     return y1 < y2;
// }
// map<int, int> my_map;
// for(auto [k, v]: my_map) {
// }

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

struct CompareY { 
    bool operator()(PointS a, PointS b) const
    { 
        return a.y < b.y || (a.y == b.y && a.s > b.s) ; 
    } 
};

bool checkLine(Point& a, Point& b, Point& c, Point& d) {
    if (max(a.x, b.x) < min(c.x, d.x) || max(a.y, b.y) < min(c.y, d.y))
        return true;
    return false;
}
bool checkInter(Point& a, Point& b, Point& c, Point& d) {
    Point c1 = b - a, c2 = c - a, c3 = d - a;
    return c1.cross(c2)  * c3.cross(c1) >= 0;
}

bool check(Point& a, Point& b, Point& c, Point& d) {
    Point c1 = b - a, c2 = c - a, c3 = d - a;
    if (checkLine(a, b, c, d) || checkLine(c, d, a, b)) 
        return false;
    if (checkInter(a, b, c, d) && checkInter(c, d, a, b)) 
       return true;
    else
        return false;
}


void solve(vector<PointS>& a, vector<pair<Point, Point>> &points) {
    set<PointS, CompareY> s;
    for (int i = 0; i < a.size(); i++) {
        PointS p = a[i];
        pair<Point, Point> p1, pL, pU;
        p1 = points[p.id];
        
        if (p.s == 1) {     // if it is has -> put into set s, compare with upper & lower
            s.insert(p);
            auto it = s.find(p);
            if(it != s.begin()) {
                auto previous = prev(it);
                pL = points[previous->id]; 
                if (check(p1.first, p1.second, pL.first, pL.second) && (p.id != previous->id)) {
                    cout << "YES\n" << p.id << " " << previous->id;
                    return;
                }
            }
           
            auto nextEl = next(it); // [ A ] s.begin() -> 0th. ith + 1 ~ nth s.end()
            if (nextEl != s.end()) { // s.end() is element after last element
                pU = points[nextEl->id];
                if (check(p1.first, p1.second, pU.first, pU.second) && (p.id != nextEl->id)) {
                    cout << "YES\n" << p.id << " " << nextEl->id;
                    return;
                }
            }
        }

        else {      // Find upper and lower of that high, pop the point out
            
            Segment segm = segments[p.id];
            // Point leftBounday = Point(segm.a, segm.b, p.id)
            // auto it = s.find(leftBoundary);
            auto it = s.find(p);
            auto nextEl = next(it);
            if (it != s.begin() && nextEl != s.end()) {
                auto previous = prev(it);
                pL = points[previous->id];
                pU = points[nextEl->id];
                if (check(pL.first, pL.second, pU.first, pU.second) && (previous->id != nextEl->id)) {
                    cout << "YES\n" << previous->id << " " << (nextEl->id);
                    return;
                }
            }
            PointS pp = PointS(p1.first.x, p1.first.y, p.id, 1); 
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
    vector<pair<Point, Point>> points(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c >> d;
        PointS p1 = PointS(a, b, i, 1); 
        PointS p2 = PointS(c, d, i, -1);
        v[2 * (i - 1)] = PointS(a, b, i, 1);     // Start point
        v[2 * (i - 1) + 1] = PointS(c, d, i, -1);    // End point  
    
        Segment s = Segment(a,b,c,d);
        segments.push_back(s);
    }

    sort(v.begin(), v.end(), [](PointS a, PointS b) {
        return (a.x < b.x || (a.x == b.x && a.s > b.s));
    });

    solve(v, points);
    return 0;
}
