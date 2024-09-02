#include<iostream>
#include<math.h>

using namespace std;

// Запись числа наоборот
int Reverse(unsigned int number) {
    unsigned int temp = 0;
    if (number & 1) {
        temp |= 1;
    }
    for (int i = 0; i < 31; i++) {

        number = number >> 1;
        temp = temp << 1;
        if (number & 1) {
            temp |= 1;
        }
    }
    return temp;
}

// Вывод числа в двоичном коде
void InBin(unsigned int number) {
    int bite;
    for (int i = 31; i >= 0; i--) {
        bite = (number >> i) & 1;
        cout << bite;
    }
    cout << endl;
}

int main()
{
    int number;
    cin >> number;
    InBin(number);
    cout << Reverse(number) << endl;
    InBin(Reverse(number));
    return 0;
}