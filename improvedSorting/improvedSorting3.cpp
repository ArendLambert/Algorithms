#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int>& a, int start, int end)
{
    int pivot = a[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (a[i] <= pivot)
        {
            swap(a[i], a[pIndex]);
            pIndex++;
        }
    }
    swap(a[pIndex], a[end]);
    return pIndex;
}

void quicksort(vector<int>& a, int start, int end)
{
    if (start >= end) {
        return;
    }
    int pivot = partition(a, start, end);
    quicksort(a, start, pivot - 1);
    quicksort(a, pivot + 1, end);
}

int main()
{
    int i, n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}