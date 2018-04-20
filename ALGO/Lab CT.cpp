// Source : http://ideone.com/qpOqBv
https://www.dyclassroom.com/dynamic-programming/0-1-knapsack-problem




// Source : http://ideone.com/qpOqBv
//https://www.dyclassroom.com/dynamic-programming/0-1-knapsack-problem

#include <bits/stdc++.h>
using namespace std;


int dp[100][100] = {0};
int picks[100][100] = {0};
int subset[100];


int knapSack(int wei[], int val[], int n, int W)
{
     // int dp[n+1][W+1];
      for(int i=0; i<=n; i++)
      {
         for(int m=0; m<=W; m++)
         {
             if(i==0 || m==0)
             {
                dp[i][m] = 0;
             }
             else if (wei[i-1] <= m)
             {
               dp[i][m] = max(val[i-1] + dp[i-1][m-wei[i-1]],  dp[i-1][m]);

                //if (dp[i][m] > dp[i-1][m])
                if (val[i-1]+dp[i-1][m-wt[i-1]] > dp[i-1][m])
                    picks[i][m]=1;
                else
                    picks[i][m]=-1;
             }
             else
             {
               picks[i][m] = -1;
               dp[i][m] = dp[i-1][m];
             }
         }
      }
     return dp[n][W];
}


void printPicks(int item, int size, int wei[])
{
	int k=0;
    while (item)
    {
        if(picks[item][size]==1)
        {
            subset[k++]=item;
            item--;
            size -= wei[item];
        }

        else
        {
            item--;
            continue;
        }
    }


    for(int i=k-1; i>=0; i--)
    {
		printf("%d ",subset[i]);
    }
}

int main()
{
    int nItems = 3;
   // int knapsackSize = 11;
   // int weights[] = {4,10,5};
   // int values[] = {15,12,8};
    int values[]  = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int  knapsackSize = 50;

    printf("Max value = %d\n",knapSack(weights,values,nItems,knapsackSize));

    printf("Subset are: ");

    printPicks(nItems,knapsackSize, weights);


    return 0;
}

















// Source : http://ideone.com/qpOqBv

#include <stdio.h>

#define max(a,b) (a > b ? a : b)

int matrix[100][100] = {0};
int picks[100][100] = {0};
int subset[100];
int knapsack(int nItems, int size, int weights[], int values[]){
    int i,j;

    for (i=1;i<=nItems;i++)
    {
        for (j=0;j<=size;j++)
        {
            if (weights[i-1]<=j)
            {
                matrix[i][j] = max(matrix[i-1][j],values[i-1]+matrix[i-1][j-weights[i-1]]);
                if (values[i-1]+matrix[i-1][j-weights[i-1]]>matrix[i-1][j])
                    picks[i][j]=1;
                else
                    picks[i][j]=-1;
            }
            else{
                picks[i][j] = -1;
                matrix[i][j] = matrix[i-1][j];
            }
        }
    }

    return matrix[nItems][size];

}

void printPicks(int item, int size, int weights[]){
	int k=0;
    while (item>0)
    {
        if (picks[item][size]==1){
            subset[k++]=item;
            item--;
            size -= weights[item];
        }

        else
        {
            item--;
        }
    }
    //Your subset here
    for(int i=k-1;i>=0;--i)
		printf("%d ",subset[i]);


    return;
}

int main(){

int nItems = 3;
    int knapsackSize = 11;
    int weights[] = {4,10,5};
    int values[] = {15,12,8};

    printf("Max value = %d\n",knapsack(nItems,knapsackSize,weights,values));

    printf("Subset are: ");

    printPicks(nItems,knapsackSize, weights);


    return 0;
}
