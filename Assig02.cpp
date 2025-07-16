
// Name: Sanskruti Shinde (149)
// Title: Assignment – Push All Zeroes to the End of the Array

#include<iostream>
using namespace std;

void merge(int arr[], int lb, int mid, int ub)
{
    int i = lb;
    int k = lb;
    int j = mid + 1;
    int b[100];

    while(i <= mid && j <= ub)
    {
        if(arr[i] != 0 && arr[j] == 0)
        {
            b[k] = arr[i];
            i++;
        }
        else if(arr[i] == 0 && arr[j] != 0)
        {
            b[k] = arr[j];
            j++;
        }
        else
        {
            b[k] = arr[i];  // Maintain relative order
            i++;
        }
        k++;
    }

    while(i <= mid)
    {
        b[k++] = arr[i++];
    }

    while(j <= ub)
    {
        b[k++] = arr[j++];
    }

    for(int l = lb; l <= ub; l++)
    {
        arr[l] = b[l];
    }
}

void merge(int arr[], int lb, int ub)
{
    int mid;
    if(lb < ub)
    {
        mid = (lb + ub) / 2;
        merge(arr, lb, mid);
        merge(arr, mid + 1, ub);
        merge(arr, lb, mid, ub);
    }
}

int main()
{
    int arr[100], n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int lb = 0;
    int ub = n - 1;

    merge(arr, lb, ub);

    cout << "Array after pushing all 0s to the end:\n";
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
