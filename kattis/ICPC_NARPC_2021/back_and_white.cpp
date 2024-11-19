 #include <iomanip>  // Include to set fixed output precision
#include <iostream> // Include for standard input and output
#include <vector>   // Include for using vectors (dynamic arrays)

using namespace std;

int main() {
  // Reading number of players n
  int n;
  cin >> n;
  
  // Initialize a vector of doubles for storing probabilities of each player winning
  vector<double> p(n);
  
  // Reading the probabilities for each player
  for(auto& x: p) cin >> x;

  // Vectors to store the positive and negative probabilities for each subset of players
  vector<double> pos(1<<n, 1.0);  // pos[mask] stores the probability of subset 'mask' winning
  vector<double> neg(1<<n, 1.0);  // neg[mask] stores the probability of subset 'mask' losing

  // Loop to calculate positive and negative probabilities for all subsets of players
  for(int mask = 0; mask < (1<<n); mask++) {
    for(int i = 0; i < n; i++) {
      // Check if the i-th player is in the current subset represented by 'mask'
      if((mask&(1<<i)) != 0) {
        pos[mask] *= p[i];       // Multiply by the probability of player i winning
        neg[mask] *= (1 - p[i]); // Multiply by the probability of player i losing
      }
    }
  }

  // dp[mask] will store the probability of a subset of players (represented by 'mask') winning the tournament
  // chance[mask] will store the cumulative probability of each subset of players progressing
  vector<double> dp(1 << n);
  vector<double> chance(1 << n);
  
  // Initially, the probability of the last subset (all players) progressing is set to 1
  chance.back() = 1;
  
  // Variable to store the final result (probability of the desired outcome)
  double ret = 0;

  // Traverse all possible subsets of players (starting from the largest and going down)
  for(int mask = (1<<n)-1; mask >= 0; mask--) {
    // If there are exactly 2 players in the subset, we add the probability to the result
    if(__builtin_popcount(mask) == 2) ret += dp[mask];
    
    // Skip subsets with 2 or fewer players, as they have already been handled
    if(__builtin_popcount(mask) <= 2) continue;
    
    // Normalize dp[mask] by dividing it by the chance of the subset progressing
    dp[mask] /= chance[mask];
    
    // Temporary container to store updates to dp values for the subset
    vector<pair<int, double>> updates;
    
    // Variable to store the total contribution to the term for updating dp values
    double term = 0;
    
    // Loop through each player and calculate the contribution to the updates
    for(int i = 0; i < n; i++) {
      // If player 'i' is not in the current subset, skip them
      if((mask&(1<<i)) == 0) continue;
      
      // Calculate the contribution to the dp value for this player:
      // 'up' and 'down' are the updated probabilities based on the player's win/loss outcome
      double up = pos[mask] / p[i] * (1 - p[i]);
      double down = neg[mask] / (1 - p[i]) * p[i];
      
      // Store the update for this player in the updates vector
      updates.emplace_back(i, up + down);
      
      // Add the update contribution to the total term
      term += updates.back().second;
    }

    // Calculate the gain for this subset based on the term
    double gain = 1 / (term);
    
    // Apply the updates for the subset by updating the dp values
    for(auto [x, pp]: updates) {
      // Calculate the scaling factor for this player
      double scalep = pp / term * chance[mask];
      
      // Update dp and chance values for the complement of the current subset
      dp[mask ^ (1 << x)] += (dp[mask] + gain) * scalep;
      chance[mask ^ (1 << x)] += scalep;
    }
  }

  // Output the final result with a precision of 17 decimal places
  cout << fixed << setprecision(17) << ret << "\n";
}
