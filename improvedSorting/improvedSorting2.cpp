#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void pyramid_sort(vector<int>& a, int n, int i) {
    int r;
    while (2 * i <= n) {
        r = 2 * i;
        if (r + 1 <= n && a[r] < a[r + 1]) {
            r++;
        }
        if (a[i] < a[r]) {
            swap(a[i], a[r]);
            i = r;
        }
        else {
            break;
        }
    }
}

int main() {
    int i, n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i < n + 1; i++) {
        cin >> a[i];
    }

    i = n / 2;
    while (i >= 1) {
        pyramid_sort(a, n, i);
        i--;
    }

    i = n;
    while (i > 1) {
        swap(a[1], a[i]);
        i--;
        pyramid_sort(a, i, 1);
    }
    for (int i = 1; i < n + 1; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
