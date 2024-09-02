#include <iostream> 

using namespace std;

int main() {
    int N;
    cin >> N;

    int* result = new int[N + 1];
    result[0] = 2;
    result[1] = 3;
    for (int i = 2; i < N; i++) {
        result[i] = result[i - 1] + result[i - 2];
    }

    cout << result[N - 1] << endl;

    return 0;
}
