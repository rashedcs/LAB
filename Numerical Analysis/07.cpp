#include<bits/stdc++.h>

void solution(int arr[20][20], int n)
{
    int k, i, l, j;

    for(j=1; j<=n; j++)
    {
        for(i=1; i<=n; i++)
        {
            if(i!=j)
            {
                c=arr[i][j]/arr[j][j];
                for(k=1; k<=n+1; k++)
                {
                    arr[i][k]=A[i][k]-c*arr[j][k];
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

    int n, arr[20][20];
    scanf("%d", &n);

    for(int i=1; i<=n; i++ )
    {
        for(int j=1; j<=n+1; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    solution(arr, n);
    
    return 0;
}
