#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

typedef int bitword;
void bitsetSet(vector<bitword>& arr, int newval, int idx) {
    int idxCol;
    int idxRow;
    idxCol = idx % 32;
    idxRow = idx >> 5;
    if (newval == 1) {
        arr[idxRow] |= (1 << (32 - idxCol) - 1);
    }
    else {
        arr[idxRow] &= ~(1 << (32 - idxCol) - 1);
    }
}

int main()
{
    int commands, wordsCount, number, index;
    cin >> wordsCount >> commands;
    vector<bitword> arr(wordsCount);
    for (int i = 0; i < wordsCount; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < commands; i++) {
        cin >> number >> index;
        bitsetSet(arr, number, index);
    }
    for (int i = 0; i < wordsCount; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}