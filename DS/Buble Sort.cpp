#include<iostream>
using namespace std;

int main()
{
    int n, arr[50];

    cout<<"Enter  number of elements :";
    cin>>n;

    cout<<"The Numbers u want to sort : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }


    for(int i=0; i<n-1; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
             swap(arr[j],arr[j+1]);
            }
        }
    }

    cout<<"Sortting element are : ";
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}

