#include <iostream>
using namespace std;

int x, y;
int main() {
   
    cin >> x >> y;

    if (y % 2 != 0) {
        cout << "impossible";
    }
    else {
        cout << "possible";
    }
    return 0;
}
