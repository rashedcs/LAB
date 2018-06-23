#include<stdio.h>

void solution(double arr[20][20], int n)
{
    double c, sum,  x[10];
    /* loop for the generation of upper triangular matrix*/
    for(int i=1; i<=n; i++) 
    {
        for(int j=1; j<=n; j++)
        {
            if(i<j)
            {
                c = arr[j][i]/arr[i][i];
                for(int k=1; k<=n+1; k++)
                {
                   arr[j][k] = arr[j][k]-c*arr[i][k];
                }
            }
        }
    }
    x[n]=arr[n][n+1]/arr[n][n];

    /* this loop is for backward substitution*/
    for(int i=n-1; i>=1; i--)
    {
        sum=0;
        for(int j=i+1; j<=n; j++)
        {
            sum += arr[i][j]*x[j];
        }
        x[i]=(arr[i][n+1]-sum)/arr[i][i];
    }
    printf("\nThe solution is: \n");
    for(int i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); 
    }
}



int main()
{
    int i,j,k,n;
    double arr[20][20];
    scanf("%d",&n);
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=(n+1); j++)
        {
            scanf("%lf",&arr[i][j]);
        }
    }
    solution(arr, n);
    
    return 0;
}
/**
input and output :
3
1 1 1 6
1 -1 1 2
2 -1 3 9
0 
1 
1 

The solution is: 

x1=1.000000	
x2=2.000000	
x3=3.000000	 
**/
