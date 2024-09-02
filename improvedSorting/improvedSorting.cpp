#include <iostream>
#include <vector>

using namespace std;

void shell_sort(vector<int>& a, int n) {
    int step = n;
    int j;
    do {
        step = step / 3 + 1;
        for (int i = step; i < n; i++) {
            int c = a[i];
            for (j = i - step; j >= 0 && a[j] > c; j -= step) {
                a[j + step] = a[j];
            }
            a[j + step] = c;
        }
    } while (step != 1);
}

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    shell_sort(a, n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}
