#include <iostream>

using namespace std;

typedef struct DateTime_s {
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;

DateTime min(const DateTime* arr, int cnt) {
    int minCnt = 0;
    DateTime minimal = arr[0];
    for (int i = 1; i < cnt; i++) {
        if (arr[i].year < minimal.year ||
            (arr[i].year == minimal.year && arr[i].month < minimal.month) ||
            (arr[i].year == minimal.year && arr[i].month == minimal.month && arr[i].day < minimal.day) ||
            (arr[i].year == minimal.year && arr[i].month == minimal.month && arr[i].day == minimal.day && arr[i].hours < minimal.hours) ||
            (arr[i].year == minimal.year && arr[i].month == minimal.month && arr[i].day == minimal.day && arr[i].hours == minimal.hours && arr[i].minutes < minimal.minutes) ||
            (arr[i].year == minimal.year && arr[i].month == minimal.month && arr[i].day == minimal.day && arr[i].hours == minimal.hours && arr[i].minutes == minimal.minutes && arr[i].seconds < minimal.seconds)) {
            minimal = arr[i];
        }
    }
    return minimal;
}


int main() {
    int N;
    cin >> N;
    DateTime* arr = new DateTime[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i].year >> arr[i].month >> arr[i].day >> arr[i].hours >> arr[i].minutes >> arr[i].seconds;
    }
    DateTime minimal = min(arr, N);
    cout << minimal.year << " " << minimal.month << " " << minimal.day << " " << minimal.hours << " " << minimal.minutes << " " << minimal.seconds;
    delete[] arr;
    return 0;
}
