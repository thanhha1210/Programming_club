#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<char> vc;
const string PARENS = "()[]{}";

vvll tree;
string labels;


ll dfs(ll u, ll p, vc& stk) { 
    auto type = PARENS.find(labels[u]);  
    
    // Check if it's an opening or closing parenthesis
    if (type % 2 == 0) 
        stk.push_back(labels[u]);  // Push opening  
    else if (!stk.empty() && stk.back() == PARENS[type - 1]) 
        stk.pop_back();           // Pop if it matches
    else 
        return 0;                 // Invalid sequence
    

    // Count valid sequences
    ll ans = stk.empty();         // Count if the stack is empty (valid sequence)
    for (auto v : tree[u]) {
        if (v == p) continue;     // Avoid going back to parent
        ans += dfs(v, u, stk);    // Recurse to children
    }

    // Restore the stack state for the parent call
    if (type % 2 == 0) {
        stk.pop_back();         // Remove opening
    } 
    else {
        stk.push_back(PARENS[type - 1]); // Restore closing
    }

    return ans; // Return the count of valid sequences found
}

int main() {
    ll n;
    cin >> n;
    cin >> labels;
    tree.resize(n);
    for (auto i = 1; i < n; ++i) {
        ll u, v;
        cin >> u >> v;
        --u; --v; // Convert to 0-based indexing
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    ll ans = 0;
    vc stk; // Stack for parentheses
    // Explore each node as a root
    for (auto root = 0; root < n; ++root) {
        ans += dfs(root, -1, stk); // Start DFS from each root
    }

    cout << ans << '\n'; // Output the result
    return 0;
}
