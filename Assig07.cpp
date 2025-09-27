#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

int isvalid(int d, int x, vector<int> task, int n)
{
    int no_of_days = 0;

    for (int i = 0; i < n; i++)
    {
        no_of_days += (task[i] + x - 1) / x;
    }

    return no_of_days;
}

int main()
{
    int n, d; 

    cout << "Enter the number of tasks: ";
    cin >> n;

    vector<int> task(n);

    cout << "Enter Number of Days the tasks should completed: ";
    cin >> d;

    cout << "Enter Tasks";
    for (int i = 0; i < n; i++)
    {
        cin >> task[i];
    }

    // Finding the value of x(ie the task should completed in one day)

    int low = 1;
    int high = *max_element(task.begin(), task.end());

    int mid = (low + high) / 2;

    while (low <= high)
    {
        int current = isvalid(d, mid, task, n);
        if (current == d)
        {
            cout << mid;
            break;
        }
        else if (current > d)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
}