// Name: Sanskruti Shinde (149)
// Assignment 1: Count number of zeroes in array (1s followed by 0s)

#include <iostream>
using namespace std;

int countZeroes(int arr[], int n) {
    int low = 0, high = n - 1, ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == 0) {
            ans = n - mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    cout << "Enter array elements (1s followed by 0s): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Number of zeroes = " << countZeroes(arr, n) << endl;
    return 0;
}