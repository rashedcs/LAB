#include<bits/stdc++.h>
using namespace std;


void addition(int x[], int m, int y[], int n)
{
        int maxim = max(m, n);
        
        int z[maxim]={0};
        
        for(int i=0;i<maxim; i++)
        {
            z[i]=x[i]*y[i];
            printf("%d ",z[i]);
        }
}


int main()
{
    int m, n, x[100]={0},y[100]={0},z[100]={0};
  //  printf("Enter the size of 1st sequence:\n");
    scanf("%d",&m);
    //printf("Enter the size of 2nd sequence:\n");
    scanf("%d",&n);
   // printf("Enter 1st sequence:");
    
    for(int i=0;i<m;i++)
    {
          scanf("%d",&x[i]);
    }
    //printf("Enter 2nd sequence:");
    for(int i=0;i<n;i++)
    {
           scanf("%d",&y[i]);

    }
    addition(x, m, y, n);

}
