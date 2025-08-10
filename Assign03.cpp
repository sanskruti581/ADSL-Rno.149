// Sanskruti Shinde Assignment 3 Roll No 149
#include <bits/stdc++.h>
using namespace std;

int countTrailingZeroes(int x)
{
    int count = 0;
    while (x >= 5)
    {
        count += x / 5;
        x /= 5;
    }
    return count;
}

int smallestNumber(int n)
{
    int low = 0, high = 5 * n, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (countTrailingZeroes(mid) >= n)
        {
            ans = mid;
            high = mid - 1; // look for smaller number
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    cout << smallestNumber(n);
    return 0;
}

/*
Example:
Input:
6
Output:
25
Explanation:
25! has 6 trailing zeroes.
*/
