#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
int k;

pair<ll, ll> rational_ratio(const string& s, int k) {
    int pos = s.find('.'); 
    string a = s.substr(0, pos);
    string fp = s.substr(pos + 1);

    string nonRep = fp.substr(0, fp.length() - k);
    string hasRep = fp.substr(fp.length() - k);

    ll numWhole = stoll(a + nonRep + hasRep); 
    ll numnonRep = stoll(a + nonRep); 

    ll basenonRep = pow(10, nonRep.size());
    ll basehasRep = pow(10, nonRep.size() + k);

    ll num = numWhole - numnonRep;
    ll dem = basehasRep - basenonRep;

    ll gc = __gcd(num, dem);
    num /= gc;
    dem /= gc;

    return {num, dem};
}

int main() {
    cin >> s >> k;

    auto result = rational_ratio(s, k);
    cout << result.first << "/" << result.second << endl;

    return 0;
}
