#include<bits/stdc++.h>
using namespace std;

void solution(double arr[20][20], int n)
{

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i!=j)
            {
                double c=arr[j][i]/arr[i][i];
                for(int k=1; k<=n+1; k++)
                {
                    arr[j][k]=arr[j][k]-c*arr[i][k];
                }
            }
        }
    }

    printf("\nSolutions : \n" );

    for(int i=1; i<=n; i++)
    {
        printf("\n x%d=%f\n",i, arr[i][n+1]/arr[i][i]);
    }
}


int main()
{

    int n;
    double arr[20][20];
    scanf("%d", &n);

    for(int i=1; i<=n; i++ )
    {
        for(int j=1; j<=n+1; j++)
        {
            scanf("%lf", &arr[i][j]);
        }
    }
    solution(arr, n);
    
    return 0;
}
