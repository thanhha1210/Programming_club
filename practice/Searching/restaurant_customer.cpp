#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        events.push_back({a, 1}); // Arrival event
        events.push_back({b, -1}); // Leaving event
    }

    // Sort events based on time
    sort(events.begin(), events.end());

    int currentCustomers = 0, maxCustomers = 0;
    for (int i = 0; i < events.size(); i++) {
        if (events[i].second == 1) // Arrival
            currentCustomers++;
        else // Leaving
            currentCustomers--;

        maxCustomers = max(maxCustomers, currentCustomers);
    }

    cout << maxCustomers << endl;

    return 0;
}
