#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long distance(long long d, int n, vector<long long>& p) {
    long long res = 0;
    for (int i = 0; i < n; i++)
        res += abs(p[i] - d);
    return res;
}

long long ternarySearch(long long l, long long r, int n, vector<long long>& p) {
    while (r >= l) {
        if (abs(r - l) <= 1)
            return min(distance(l, n, p), distance(r, n, p));
        long long m1 = (2 * l + r) / 3;
        long long m2 = (l + 2 * r) / 3;
        long long y1 = distance(m1, n, p), y2 = distance(m2, n, p);
         
        if (y1 == y2) {
            l = m1; r = m2;
        }
        else if (y1 < y2)
            r = m2 - 1;
        else
            l = m1 + 1;       
    }
    // Return a default value if no optimal value is found
    return -1; 
}

int main() {
    int n;
    cin >> n;
    vector<long long> p(n);
    long long maxx = 0, minx = 1e9;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (minx > p[i]) minx = p[i]; 
        if (maxx < p[i]) maxx = p[i];
    }
    cout << ternarySearch(minx, maxx, n, p);
        
    return 0;
}
