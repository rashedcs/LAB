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
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }

    printf("\nSolutions : \n" );

    for(i=1; i<=n; i++)
    {
        printf("x%d = %f\n", i+1, (float)arr[i][n] / (float)arr[i][i]);
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
