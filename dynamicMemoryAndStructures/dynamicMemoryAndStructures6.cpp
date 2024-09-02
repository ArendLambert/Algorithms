#include <iostream> 
using namespace std;

void reverse(char* start, int len) {
    char temp;
    char* end = start + len - 1;
    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

int main()
{
    int n;
    char str[101];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> str;
        reverse(str, strlen(str));
        cout << str << "\n";
    }
    return 0;
}