#include<iostream> 

using namespace std;

int main()
{
    unsigned int base;
    int count = 0, count2 = 0;
    cin >> base;
    while (base > 0) {
        if (base & 1) {
            count++;
        }
        else if ((count2 < count)) {
            count2 = count;

        }
        else {
            count = 0;
        }
        base = base >> 1;
    }
    if (count > count2) {
        cout << count;
    }
    else {
        cout << count2;
    }
    return 0;
}