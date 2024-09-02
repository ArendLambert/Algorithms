#define _CRT_SECURE_NO_WARNINGS
// для использования sscanf и printf согласно заданию

#include <iostream>

using namespace std;

int readTime(char* iStr, int* oHours, int* oMinutes, int* oSeconds) {
    int h = 0, m = 0, s = 0, n, succes = 0;
    n = sscanf(iStr, "%d:%d:%d", &h, &m, &s);
    if (h < 0 || h > 23 || m < 0 || m > 59 || s < 0 || s > 59 || n < 2) {
        cout << "0 ";
        if (oHours) {
            *oHours = -1;
        }
        if (oMinutes) {
            *oMinutes = -1;
        }
        if (oSeconds) {
            *oSeconds = -1;
        }
    }
    else {
        succes = 1;
        cout << succes << " ";
        if (oHours) {
            *oHours = h;
        }
        if (oMinutes) {
            *oMinutes = m;
        }
        if (oSeconds) {
            *oSeconds = s;
        }
    }

    if (oHours) {
        printf("%d ", *oHours);
    }
    if (oMinutes) {
        printf("%d ", *oMinutes);
    }
    if (oSeconds) {
        printf("%d ", *oSeconds);
    }
    printf("\n");
    return 0;
}

int main() {
    char iStr[16];
    int oHours = -1, oMinutes = -1, oSeconds = -1;
    while (scanf("%16s", iStr) == 1)
    {
        readTime(iStr, &oHours, &oMinutes, &oSeconds);
        readTime(iStr, &oHours, &oMinutes, 0);
        readTime(iStr, &oHours, 0, 0);

    }
    return 0;
}
