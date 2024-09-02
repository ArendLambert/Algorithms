#include<iostream>
#include<math.h>

using namespace std;

int main()
{
    int amount, number, count = 0;
    cin >> amount;
    while (amount > 0) {
        cin >> number;
        for (int i = 0; i < 32; i++) {
            if (!(number & 1)) {
                count++;
            }
            else {
                break;
            }
            number = number >> 1;
        }
        cout << pow(2, count) << endl;
        count = 0;
        amount--;
    }

    return 0;
}