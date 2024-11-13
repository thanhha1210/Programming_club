#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s1;
    for (int i = 1; i <= 6; i ++)
        if (i != 4 && i != 5)
            s1.insert(i);
    for (auto itr = s1.begin(); itr != s1.end(); itr++)
        cout << *itr << ' ';
    cout << '\n';
    cout << *s1.upper_bound(1) << '\n';
    cout << *s1.upper_bound(4) << '\n';
    cout << *s1.upper_bound(5) << '\n';
    if (s1.upper_bound(10) != s1.end()) {
        cout << *s1.upper_bound(10);
    }
   
    return 0;
}