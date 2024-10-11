#include <bits/stdc++.h>
using namespace std;
#define rep(i, j, n) for (int i = j; i < n; i++)
typedef vector<char> vc;
typedef vector<int> vi;
typedef long long ll;
const ll INF = 1e7;
int lMax = -INF, lMin = INF, n;
int posLMax, posLMin;
string s;

vi d;

int main() {
   char c ;
   int lowval = 0, hival = 0, lowpos = -1, hipos = -1, pos = 0, curval = 0 ;
   while (cin >> c) {
      if (c == 'R') {
         curval++ ;
         if (curval > hival) {
            hival = curval ;
            hipos = pos ;
         }
         pos++ ;
      } else if (c == 'B') {
         curval-- ;
         if (curval < lowval) {
            lowval = curval ;
            lowpos = pos ;
         }
         pos++ ;
      }
   }
   if (lowpos > hipos)
      swap(lowpos, hipos) ;
   cout << (lowpos+2) << " " << (hipos+1) << endl ;
}
    // cin >> s;
    // n = s.length();
 
    // d.assign(n + 1, 0);
    // rep(i, 0, n) {
    //     if (s[i] == 'B')
    //         d[i + 1] = d[i] - 1;
    //     else 
    //         d[i + 1] = d[i] + 1;
    // }

    // rep(i, 1, n + 1) {
    //     if (d[i] > lMax) {
    //         lMax = d[i];
    //         posLMax = i;
    //     } 
    //     if (d[i] < lMin) {
    //         lMin = d[i];
    //         posLMin = i;
    //     }
    // }

    // if (posLMin > posLMax) {
    //     swap(posLMin, posLMax);
    // }

    // cout << (posLMin + 1) << " " << posLMax << endl;
    
