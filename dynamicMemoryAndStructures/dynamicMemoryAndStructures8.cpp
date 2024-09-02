#include <iostream>
#include <cstring>

using namespace std;

char* concat(char* pref, char* suff) {
    while (*pref != '\0')
        pref++;
    while (*suff != '\0')
    {
        *pref = *suff;
        pref++;
        suff++;
    }
    *pref = '\0';
    return pref;
}

int main() {
    int n;
    cin >> n;
    char* str1;
    char* str2 = new char[101];
    str1 = new char[101 * n];
    cin >> str1;
    char* temp = str1;
    for (int i = 1; i < n; i++) {
        cin >> str2;
        temp = concat(temp, str2);
    }
    cout << str1;
    delete[] str2;
    delete[] str1;
    return 0;
}
