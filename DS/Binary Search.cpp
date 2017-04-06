
#include<iostream>
using namespace std;

int main()
{
 int first,last,middle,n,key,arr[50];

 cout<<"Enter the number of element : ";
 cin>>n;

 cout<<"Enter the elements : ";
 for(int i=0; i<n; i++)
 {
   cin>>arr[i];
 }

 cout<<"Enter value to search : ";
 cin>>key;

 first=0;
 last=n-1;

 while(first<=last)
 {
   middle=(first+last)/2;

   if(key>arr[middle])          first=middle+1;

   else if(key<arr[middle])     last=middle-1;

   else if(key==arr[middle]) 
   {
     cout<<"It is found at  "<<middle<<endl;
     break;
   }

 }
 if(first>last)     cout<<"Not found "<<endl;
 return 0;

}
