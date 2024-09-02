#include <iostream>
#define MOD 1000000007 

using namespace std;

int main() {
    int N;
    cin >> N;

    int* dp = new int[N + 1];
    for (int i = 0; i <= N; i++) {
        dp[i] = 0;
    }
    dp[0] = 1;

    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            dp[j] = (dp[j] + dp[j - i]) % MOD;
        }
    }

    cout << dp[N];
}
