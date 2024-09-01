#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    int n, a, b;
    cin >> n;
    set<pair<int, int>> st;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        auto it = st.lower_bound({a, a});
        pair<int, int> first = (it == st.begin()) ? make_pair(-1, -1) : *prev(it);

        it = st.upper_bound({b, b});
        pair<int, int> last = (it == st.begin()) ? make_pair(-1, -1) : *prev(it);

        vector<pair<int, int>> toDelete;
    




    
        
        pair<int, int> newE = {first.first, last.second};
        
        st.insert(newE);
        
        cout << st.size() << endl;
    }

    return 0;
}
