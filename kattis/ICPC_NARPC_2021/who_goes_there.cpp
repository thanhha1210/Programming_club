#include <iostream>
#include <vector>
using namespace std;

int main() {
    int C, N;
    cin >> C >> N;
    
    vector<int> teams(N);
    for (int i = 0; i < N; i++) {
        cin >> teams[i];
    }
    
    vector<int> accepted(N, 0); // To store how many teams are accepted from each school
    int wave = 0;
    
    // Allocate teams in waves
    while (C > 0) {
        bool allocated = false;
        for (int i = 0; i < N; i++) {
            if (teams[i] > wave) { // If the school has more teams in the current wave
                accepted[i]++;
                C--;
                allocated = true;
                if (C == 0) break; // Stop if capacity is full
            }
        }
        if (!allocated) break; // No teams allocated in this wave, stop the process
        wave++;
    }
    
    // Output the results
    for (int i = 0; i < N; i++) {
        cout << accepted[i] << "\n";
    }
    
    return 0;
}