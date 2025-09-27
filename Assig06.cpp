#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int arr[n];
    cout << "Enter stock prices for " << n << " days: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int maxSoFar = 0;
    int profit = 0;

    // to store buy/sell info
    int buyDays[n], sellDays[n];
    int count = 0;

    // go from last day to first
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxSoFar)
        {
            maxSoFar = arr[i];
        }
        else
        {
            profit += (maxSoFar - arr[i]);
            buyDays[count] = i;
            sellDays[count] = maxSoFar;
            count++;
        }
    }

    cout << "\nMaximum Profit = " << profit << endl;
    cout << "Transactions:\n";
    // print in correct order (Day 1 to Day N)
    for (int i = count - 1; i >= 0; i--)
    {
        cout << "Buy on Day " << buyDays[i] + 1 << " at price " << arr[buyDays[i]];
        cout << " → Sell at price " << sellDays[i] << endl;
    }

    return 0;
}
