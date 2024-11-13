#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int W, S, C, K;
    cin >> W >> S >> C >> K;

    if(K == 0) {
        cout << "No" << endl;
        return 0;
    }
    if(S == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(W == 0 && C == 0){
        cout << "Yes" << endl;
        return 0;
    }
    if(K >= W + C + S){
        cout << "Yes" << endl;
        return 0;
    }
    if(S <= K && W + C <= 2*K){
        cout << "Yes" << endl;
        return 0;
    }
    if(S <= 2 * K && W + C <= K){
        cout << "Yes" << endl;
        return 0;
    }
    int first = W + S;
    int second = W + C;
    int third = S + C;

    vector<int> sort_ = {first, second, third};
    sort(sort_.begin(), sort_.end());

    if(sort_[0] < K)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}