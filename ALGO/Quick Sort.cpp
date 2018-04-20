#include <iostream>
#include <algorithm>
using namespace std;


int partition(int arr[], int start, int end)
{
    int pivotValue = arr[start];
    int pivotPosition = start;

    for (int i=start+1; i<=end; i++)
    {
        if (pivotValue > arr[i])
        {
            swap(arr[pivotPosition+1], arr[i]);
            swap(arr[pivotPosition] , arr[pivotPosition+1]);
            pivotPosition++;
        }
    }

    return pivotPosition;
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int pi = partition(arr, low, high);
        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int main()
{
    int arr[10],n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
      cin>>arr[i];
    }

    quickSort(arr, 0, n-1);

    for(int k = 0; k<n; k++)   cout<<arr[k]<<" ";

    return 0;
}
