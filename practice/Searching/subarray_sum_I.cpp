#include <bits/stdc++.h>
using namespace std;

int count(long long n, long long k, vector<long long>& p) {
    int cnt = 0;
    long long sum = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        sum += p[right];
        
        // Move the left pointer to the right until the sum is less than or equal to k
        while (sum > k && left <= right) {
            sum -= p[left];
            left++;
        }
        
        // Check if the current subarray sum is equal to k
        if (sum == k)
            cnt ++;
    }

    return cnt;
}

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << count(n, k, a) << endl;
    return 0;
}
