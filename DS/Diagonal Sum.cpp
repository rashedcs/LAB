#include<iostream>
using namespace std;

int main()
{
int T,i,j,ar[10][10],sum1=0,sum2=0,n;
cin>>T;
while(T--)
{
    sum1=0;
    sum2=0;
    
    cin>>n;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        cin>>ar[i][j];
      }
    }
    
    for(i=0;i<n;i++)
    {
       for(j=0;j<n;j++)
       {
            if(i==j)            sum1+=ar[i][j];
            if((i+j)==(n-1))    sum2+=ar[i][j];
       }
    }
    
    cout<<(sum1+sum2);
 }
return 0;
}




#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int tc, n, arr[10][10];
	int SumDiagonal;
	cin>>tc;
	while(tc--)
	{
	   SumDiagonal = 0;
	   cin>>n;
	   for(int i=0;i<n;i++)
       {
         for(int j=0;j<n;j++)
         {
          cin>>arr[i][j];
         }
       }
       
        for(int i=0; i<n; i++)
        {
            SumDiagonal = SumDiagonal + arr[i][i];
            SumDiagonal = SumDiagonal + arr[i][n-i-1];
        }
	    cout<<SumDiagonal<<endl;
	}
	return 0;

}
