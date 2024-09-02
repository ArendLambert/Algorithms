#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<int> sequance;
    vector<int> prev(n, -1);
    vector<int> maxLength(n);
    vector<int> result;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(sequance.begin(), sequance.end(), arr[i]);
        if (it == sequance.end()) {
            prev[i] = sequance.empty() ? -1 : maxLength[sequance.size() - 1];
            maxLength[sequance.size()] = i;
            sequance.push_back(arr[i]);
        }
        else {
            *it = arr[i];
            if (it == sequance.begin()) {
                prev[i] = -1;
            }
            else {
                prev[i] = maxLength[(it - sequance.begin()) - 1];
            }
            maxLength[it - sequance.begin()] = i;
        }
    }

    int i = maxLength[sequance.size() - 1];
    while (i >= 0) {
        result.push_back(i);
        i = prev[i];
    }

    reverse(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int i : result) {
        cout << "A[" << i + 1 << "] = " << arr[i] << '\n';
    }

    return 0;
}