#include <iostream> 
#include <vector> 
#include <string> 
#include <algorithm> 

using namespace std;

int getButton(char c) {
    if (c == 'O' || c == 'Q' || c == 'Z') return 0;
    if (c >= 'A' && c <= 'C') return 2;
    if (c >= 'D' && c <= 'F') return 3;
    if (c >= 'G' && c <= 'I') return 4;
    if (c >= 'J' && c <= 'L') return 5;
    if (c >= 'M' && c <= 'O') return 6;
    if (c >= 'P' && c <= 'S') return 7;
    if (c >= 'T' && c <= 'V') return 8;
    if (c >= 'W' && c <= 'Y') return 9;
    return -1;
}


int main() {
    string company, phoneNumber;
    cin >> company >> phoneNumber;

    vector<vector<int>> dp(company.size() + 1, vector<int>(phoneNumber.size() + 1, 0));

    for (int i = 0; i <= company.size(); i++) {
        for (int j = 0; j <= phoneNumber.size(); j++) {
            if (i > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            if (j > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
            if (i > 0 && j > 0) {
                if (company[i - 1] == phoneNumber[j - 1] || getButton(company[i - 1]) == phoneNumber[j - 1] - '0') {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
            }
        }
    }

    cout << dp[company.size()][phoneNumber.size()] << endl;

    return 0;
}
