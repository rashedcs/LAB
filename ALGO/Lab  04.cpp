#include<bits/stdc++.h>

using namespace std;

int a[1000];

void DAndCMaxMin(int i,int j,int &maxx,int &minx)
{
    int min1,max1;

    if(i==j)
    {

    maxx=a[i];

    minx=a[i];

    return;

    }

    if( i==j-1 )

    {

        if(a[i]<a[j]){

            maxx=a[j];

            minx=a[i];

        }

        else

        {

            maxx=a[i];

            minx=a[j];

        }

        return;

    }

    else

    {

        int mid=(i+j)/2;



        DAndCMaxMin(i,mid,maxx,minx);

        DAndCMaxMin(mid+1,j,max1,min1);


        if(maxx<max1)

            maxx=max1;

        if(minx>min1)

            minx=min1;

    }
}



int main()
{

    int n;

    while(cin>>n)

    {

        int maxx=0,minx=0;

        for(int i=0;i<n;i++)
            cin>>a[i];

        DAndCMaxMin(0,n-1,maxx,minx);

        cout<<"Maximum value is "<<maxx<<endl;

        cout<<"Minimum value is "<<minx<<endl;

    }
    return 0;
}




int binarySearch(int[] array, int value, int left, int right) {
      if (left > right)
            return -1;
      int middle = (left + right) / 2;
      if (array[middle] == value)
            return middle;
      else if (array[middle] > value)
            return binarySearch(array, value, left, middle - 1);
      else
            return binarySearch(array, value, middle + 1, right);           
}


int binarySearch(int arr[], int value, int left, int right) {
      while (left <= right) {
            int middle = (left + right) / 2;
            if (arr[middle] == value)
                  return middle;
            else if (arr[middle] > value)
                  right = middle - 1;
            else
                  left = middle + 1;
      }
      return -1;
}
