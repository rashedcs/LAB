//http://ideone.com/QHg6H3
//Best resource : http://zobayer.blogspot.com/2010/09/threaded-merge-sort.html
//Modified Source Code :   http://code.geeksforgeeks.org/yy6559

//http://ideone.com/2Z23BQ
#include<bits/stdc++.h>
using namespace std;

#define mx 10


 void merge(int arr[], int l, int m,  int h)
 {
   cout<<"Ban Function "<<endl;
    int l1, l2, i;

    l1 = l;
    l2 = m + 1;
    i  = l;

    int b[h+1];
  //  int *b = new int [h+l+1];  avabe dile dynamic memory allocation.
    while(l1<=m && l2<=h)
    {
      if(arr[l1]<=arr[l2])
      {
         b[i++] = arr[l1++];
      }

      else
      {
         b[i++] = arr[l2++];
      }
    }

    while(l1<=m)
    {
       b[i++] = arr[l1++];
    }

    while(l2<=h)
    {
       b[i++] = arr[l2++];
    }

    for(i = l; i<=h; i++)
    {
       arr[i] = b[i];
    }
  //delete b;
}


void sortion(int arr[], int low, int high)
{
   int mid;

   if(low < high)
   {

      mid = (low + high) / 2;
     // cout<<"Bangla "<<low<<" "<<mid<<" "<<high<<endl;
     // for(int i=0; i<mx; i++)    cout<<arr[i]<<" "; cout<<endl;

      sortion(arr, low, mid);
     // cout<<"Ishe "<<low<<" "<<mid<<" "<<high<<endl;
     // for(int i=0; i<mx; i++)    cout<<arr[i]<<" "; cout<<endl;

      sortion(arr, mid+1, high);
   //   cout<<"Rashed "<<low<<" "<<mid<<" "<<high<<endl;
      //for(int i=0; i<mx; i++)    cout<<arr[i]<<" "; cout<<endl;

      merge(arr, low, mid, high);
     // cout<<"Shas "<<low<<" "<<mid<<" "<<high<<endl;
     // for(int i=0; i<mx; i++)    cout<<arr[i]<<" "; cout<<endl;
  
   }
}

int main()
{
   int i;
   int arr[mx];

   for(i=0; i<mx; i++)   cin>>arr[i];

   sortion(arr,0, mx-1);

   for(i=0; i<mx; i++)   cout<<arr[i]<<" ";

   return 0;
}


























Output:
 stdin copy
3 6 9 8 5 2 1 4 7 10
  stdout copy
Bangla 0 4 9
3 6 9 8 5 2 1 4 7 10 
Bangla 0 2 4
3 6 9 8 5 2 1 4 7 10 
Bangla 0 1 2
3 6 9 8 5 2 1 4 7 10 
Bangla 0 0 1
3 6 9 8 5 2 1 4 7 10 
Ishe 0 0 1
3 6 9 8 5 2 1 4 7 10 
Rashed 0 0 1
3 6 9 8 5 2 1 4 7 10 
Ban Function 
Shas 0 0 1
3 6 9 8 5 2 1 4 7 10 
Ishe 0 1 2
3 6 9 8 5 2 1 4 7 10 
Rashed 0 1 2
3 6 9 8 5 2 1 4 7 10 
Ban Function 
Shas 0 1 2
3 6 9 8 5 2 1 4 7 10 
Ishe 0 2 4
3 6 9 8 5 2 1 4 7 10 
Bangla 3 3 4
3 6 9 8 5 2 1 4 7 10 
Ishe 3 3 4
3 6 9 8 5 2 1 4 7 10 
Rashed 3 3 4
3 6 9 8 5 2 1 4 7 10 
Ban Function 
Shas 3 3 4
3 6 9 5 8 2 1 4 7 10 
Rashed 0 2 4
3 6 9 5 8 2 1 4 7 10 
Ban Function 
Shas 0 2 4
3 5 6 8 9 2 1 4 7 10 
Ishe 0 4 9
3 5 6 8 9 2 1 4 7 10 
Bangla 5 7 9
3 5 6 8 9 2 1 4 7 10 
Bangla 5 6 7
3 5 6 8 9 2 1 4 7 10 
Bangla 5 5 6
3 5 6 8 9 2 1 4 7 10 
Ishe 5 5 6
3 5 6 8 9 2 1 4 7 10 
Rashed 5 5 6
3 5 6 8 9 2 1 4 7 10 
Ban Function 
Shas 5 5 6
3 5 6 8 9 1 2 4 7 10 
Ishe 5 6 7
3 5 6 8 9 1 2 4 7 10 
Rashed 5 6 7
3 5 6 8 9 1 2 4 7 10 
Ban Function 
Shas 5 6 7
3 5 6 8 9 1 2 4 7 10 
Ishe 5 7 9
3 5 6 8 9 1 2 4 7 10 
Bangla 8 8 9
3 5 6 8 9 1 2 4 7 10 
Ishe 8 8 9
3 5 6 8 9 1 2 4 7 10 
Rashed 8 8 9
3 5 6 8 9 1 2 4 7 10 
Ban Function 
Shas 8 8 9
3 5 6 8 9 1 2 4 7 10 
Rashed 5 7 9
3 5 6 8 9 1 2 4 7 10 
Ban Function 
Shas 5 7 9
3 5 6 8 9 1 2 4 7 10 
Rashed 0 4 9
3 5 6 8 9 1 2 4 7 10 
Ban Function 
Shas 0 4 9
1 2 3 4 5 6 7 8 9 10 
