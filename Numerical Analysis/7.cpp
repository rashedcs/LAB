#include<stdio.h>

void solution(int arr[20][20], int n)
{
    int k, i, l, j;

    for(k=0; k<n; k++ )
    {
        for(i=0; i<=n; i++ )
        {
            l = arr[i][k];
            for(j=0; j<=n; j++ )
            {
                if(i!=k)  arr[i][j] = (arr[k][k]*arr[i][j])-(l*arr[k][j]);
            }
        }
    }
    
    printf("\nSolutions : \n" );

    for(i=0; i<n; i++ )
    {
        printf("x%d = %f\n", i+1, (float)arr[i][n] / (float)arr[i][i]);
    }

}


int main()
{

    int n, arr[20][20];
    scanf("%d", &n);

    for(int i=0; i<n;i++ )
    {
        for(int j=0; j<n+1; j++ )
        {
            scanf("%d", &arr[i][j]);
        }
    }
    solution(arr, n);
    
    return 0;
}
