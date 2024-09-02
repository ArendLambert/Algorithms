#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sortTransactions(int N, vector<int>& payment, vector<int>& shoulders, vector<int>& time)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (time[i] > time[j])
            {
                swap(time[i], time[j]);
                swap(payment[i], payment[j]);
                swap(shoulders[i], shoulders[j]);
            }
        }
    }
}

void calculateMaxPayment(vector<int>& maxPayment, int N, vector<int>& payment, vector<int>& shoulders, vector<int>& time)
{
    sortTransactions(N, payment, shoulders, time);
    for (int i = 0; i < N; i++)
    {
        int currentMaxPayment = payment[i];
        for (int j = 0; j < i; j++)
        {
            if (maxPayment[j] != 0)
            {
                int timeDifference = time[i] - time[j];
                int shouldersDifference = abs(shoulders[i] - shoulders[j]);
                if (shouldersDifference <= timeDifference)
                    currentMaxPayment = max(currentMaxPayment, maxPayment[j] + payment[i]);
            }
        }
        maxPayment[i] = currentMaxPayment;
    }
}

void outputMaxPayment(vector<int> maxPayment)
{
    cout << *max_element(maxPayment.begin(), maxPayment.end());
}

int main()
{
    int N, K, T;
    cin >> N >> K >> T;
    vector<int> time(N), payment(N), shoulders(N);
    vector<int> maxPayment(N);
    for (int i = 0; i < N; i++)
        cin >> time[i];
    for (int i = 0; i < N; i++)
        cin >> payment[i];
    for (int i = 0; i < N; i++)
        cin >> shoulders[i];
    for (int i = 0; i < N; i++)
    {
        if (time[i] < shoulders[i])
            payment[i] = 0;
    }
    calculateMaxPayment(maxPayment, N, payment, shoulders, time);
    outputMaxPayment(maxPayment);
    return 0;
}