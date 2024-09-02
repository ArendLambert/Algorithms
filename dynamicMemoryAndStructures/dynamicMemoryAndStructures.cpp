#include <iostream>

using namespace std;

void printTime(int h, int m, int s) {
    printf("%02d:%02d:%02d\n", h, m, s);
}

int main() {
    int count, h, m, s;
    cin >> count;
    for (count; count > 0; count--) {
        cin >> h >> m >> s;
        printTime(h, m, s);
    }
    return 0;
}
