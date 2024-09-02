#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> sequence(N);
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    vector<vector<bool>> dp(N + 1, vector<bool>(2 * K + 1, false));
    dp[0][sequence[0] % K + K] = true;

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 2 * K; j++) {
            if (dp[i - 1][j]) {
                int next_plus = (j + sequence[i]) % K + K;
                int next_minus = (j - sequence[i]) % K + K;
                dp[i][next_plus] = true;
                dp[i][next_minus] = true;
            }
        }
    }
    for (int j = 0; j < 2 * K; j++) {
        if (dp[N - 1][j] && j % K == 0) {
            cout << "Divisible" << endl;
            return 0;
        }
    }

    cout << "Not divisible" << endl;
    return 0;
}