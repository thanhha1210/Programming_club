#include <bits/stdc++.h>
using namespace std;


void display(const vector<pair<int,int>>& a) {
    for (auto x : a)
        cout << x.first << " ";
    cout << endl;
    for (auto x : a)
         cout << x.second << " ";
    cout << endl;
}

int main() {
    int t, n;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        vector<pair<int, int>>a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; i++) {
           cin >> a[i].second;
        }
        
        sort(a.begin(), a.end());
        display(a);
           
    }

}