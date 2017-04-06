
#include <iostream>
using namespace std;

int main()
{
   int arr[40], key,n,flag=0;

   cout<<"Enter the number of elements in array : ";
   cin>>n;

   cout<<"The numbers are : ";
   for (int i=0; i<n; i++)
   {
    cin>>arr[i];
   }

   cout<<"Enter the number to search : ";
   cin>>key;

   for (int i=0; i<n; i++)
   {
      if (arr[i]==key)
      {
         flag=1;
         cout<<"The number is found at "<<i;
         break;
      }
   }

   if (flag!=1)  cout<<"Sorry, The number is not found "<<endl;

   return 0;
}
