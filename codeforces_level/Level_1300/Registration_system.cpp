#include <bits/stdc++.h>
using namespace std;

const long long MAXX = 1e7 + 19;

long long hashString(const string& s) {
    long long res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = (res * 19 + s[i]) % MAXX;
    }
    return res;
}


int main() {
    long long n;
    string s;
    cin >> n;
    vector<long long> map(2 * 1e7, 0);
    while (n--) {
        cin >> s;
        long long index = hashString(s);
        if (map[index] == 0) {
            cout << "OK" << endl;
            map[index]++;
        } 
        else {
            int k = map[index];
            string c = to_string(k);
            cout << s + c << endl;
            map[index]++;    
        }
    }
    return 0;
}


