#include<bits/stdc++.h>
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


    for(int i=0; i<n; i++)
    {
        for(int j=i; j>=0; j--)
        {
            if(arr[j]>arr[j+1])
            {
              swap(arr[j+1],arr[j]);
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
