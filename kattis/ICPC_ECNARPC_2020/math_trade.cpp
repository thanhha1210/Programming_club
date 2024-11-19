#include <bits/stdc++.h>
using namespace std;

#define rep(i, j, n) for (int i = j; i < n; i++)

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef map<string, ll> msll;

msll bag;
string a, b, c;
vvll adj;
vll indegree, longest_cycle;
vll visited;
ll n, cnt = 1;

// Function to find the longest cycle using DFS
ll dfs(ll v, vll &stack, vll &pos_in_stack) {
    // visit: 0 -> unvisited, 1 -> current visited, 2 -> full process
    visited[v] = 1;
    stack.push_back(v);
    pos_in_stack[v] = stack.size() - 1;

    for (ll u : adj[v]) {
        if (visited[u] == 0) { // Not visited
            ll cycle_length = dfs(u, stack, pos_in_stack);
            if (cycle_length > 0) return cycle_length;
        } 
        else if (visited[u] == 1) { // Found a cycle
            return stack.size() - pos_in_stack[u];
        }
    }

    stack.pop_back();
    visited[v] = 2;
    return 0;
}

// Function to find the longest cycle in the graph
void find_longest_cycle() {
    visited.assign(cnt + 1, 0);
    vll stack, pos_in_stack(cnt + 1, -1);
    ll max_cycle_length = 0;

    // Perform DFS on each unvisited node to detect cycles
    rep(v, 1, cnt) {
        if (visited[v] == 0) {
            ll cycle_length = dfs(v, stack, pos_in_stack);
            max_cycle_length = max(max_cycle_length, cycle_length);
        }
    }

    // Output result
    if (max_cycle_length == 0) {
        cout << "No trades possible\n";
    } else {
        cout << max_cycle_length << "\n";
    }
}

int main() {
    cin >> n;
    adj.resize(2 * n + 1);
    indegree.resize(2 * n + 1, 0);
    rep(i, 0, n) {
        cin >> a >> b >> c;
        if (bag.find(b) == bag.end()) bag[b] = cnt++;
        if (bag.find(c) == bag.end()) bag[c] = cnt++;
        adj[bag[b]].push_back(bag[c]);
        indegree[bag[c]]++;
    }
    
    find_longest_cycle();
    return 0;
}
