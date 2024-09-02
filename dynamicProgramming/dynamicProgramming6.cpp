#include <iostream>
#include <vector>

using namespace std;

void print(int idx, const vector<int>& p, const vector<int>& a) {
    if (p[idx] != -1) {
        print(p[idx], p, a);
    }
    cout << "A[" << idx << "] = " << a[idx] << endl;
}

int main() {
    int N;
    cin >> N;
    vector<int> sequance(N + 1);
    vector<int> maxLength(N + 1, 1);
    vector<int> prev(N + 1, -1);
    for (int i = 1; i <= N; i++) {
        cin >> sequance[i];
        for (int j = 1; j < i; j++) {
            if (sequance[j] < sequance[i] && maxLength[j] + 1 > maxLength[i]) {
                maxLength[i] = maxLength[j] + 1;
                prev[i] = j;
            }
        }
    }
    int max_idx = 1;
    for (int i = 2; i <= N; i++) {
        if (maxLength[i] > maxLength[max_idx]) {
            max_idx = i;
        }
    }
    cout << maxLength[max_idx] << endl;
    print(max_idx, prev, sequance);
    return 0;
}