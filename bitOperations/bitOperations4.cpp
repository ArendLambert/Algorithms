#define _CRT_SECURE_NO_WARNINGS
// для использования scanf согласно постановке задания

#include<iostream>
#include<vector>
#include<stdio.h>
using namespace std;
typedef unsigned int bitword;
void bitsetZero(vector<bitword>& arr, int num)
{
    arr.resize(num / 32 + 1);
    int i = 0;
    while (i < num / 32 + 1) {
        arr[i] &= (0 << i);
        i = i + 1;
    }
}
int bitsetGet(vector<bitword>& arr, int idx) {
    int idx2;
    idx2 = idx % 32;
    idx = idx >> 5;
    return (arr[idx] >> idx2) & 1;
}
void bitsetSet(vector<bitword>& arr, int idx, int newval) {
    int idxCol;
    int idxRow;
    idxCol = idx % 32;
    idxRow = idx >> 5;
    if (newval == 1) {
        arr[idxRow] |= (1 << idxCol);
    }
    else {
        arr[idxRow] &= ~(1 << idxCol);
    }

}
int bitsetAny(vector<bitword>& arr, int left, int right) {
    int firstWord = left >> 5;
    int secondWord = right >> 5;
    int firstBit = left % 32;
    int secondBit = right % 32;
    if (firstWord == secondWord) {
        bitword mask = ((1 << (right - left)) - 1) << firstBit;
        return (arr[firstWord] & mask) != 0;
    }
    else {
        bitword mask = ~((1 << firstBit) - 1);
        if ((arr[firstWord] & mask) != 0)
            return 1;
    }

    for (int i = firstWord + 1; i < secondWord; i++) {
        if (arr[i] != 0)
            return 1;
    }

    bitword mask = (1 << secondBit) - 1;
    return (arr[secondWord] & mask) != 0;
}

int main()
{

    vector<bitword> arr;
    int command;
    int commands;
    unsigned int temp;
    ios_base::sync_with_stdio(false);
    scanf("%d", &commands);
    while (commands > 0) {
        scanf("%d", &command);
        switch (command)
        {
        case 0:
        {
            scanf("%d", &temp);
            bitsetZero(arr, temp);
            break;
        }
        case 1:
        {
            scanf("%d", &temp);
            printf("%d \n", bitsetGet(arr, temp));
            break;
        }
        case 2:
        {
            int value;
            scanf("%d%d", &temp, &value);
            bitsetSet(arr, temp, value);
            break;
        }
        case 3:
        {
            unsigned int left, right;
            scanf("%d%d", &left, &right);
            if (bitsetAny(arr, left, right) == 1) {
                printf("some\n");
            }
            else {
                printf("none\n");
            }
            break;
        }
        default:
            break;
        }
        commands = commands - 1;
    }
    return 0;
}