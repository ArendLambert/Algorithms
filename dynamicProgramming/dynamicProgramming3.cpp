#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> weight(N + 1), cost(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> weight[i] >> cost[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));
    vector<vector<int>> take(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= W; j++) {
            if (weight[i] <= j) {
                if (cost[i] + dp[i - 1][j - weight[i]] > dp[i - 1][j]) {
                    dp[i][j] = cost[i] + dp[i - 1][j - weight[i]];
                    take[i][j] = 1;
                }
                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
            else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int k = 0, totalWeight = 0, totalCost = 0;
    vector<int> items;

    for (int i = N; i > 0; i--) {
        if (take[i][W]) {
            k++;
            totalWeight += weight[i];
            totalCost += cost[i];
            items.push_back(i);
            W -= weight[i];
        }
    }

    reverse(items.begin(), items.end());

    cout << k << " " << totalWeight << " " << totalCost << endl;

    for (auto item : items) {
        cout << item << " ";
    }

    return 0;
}
