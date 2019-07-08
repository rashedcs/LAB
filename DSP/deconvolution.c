//A program of matrix multiplication
#include<stdio.h>

int main()
{
    int i,j,n,x_size,y_size,h_size,sum=0,temp;
    printf("Enter number of output samples: ");
    scanf("%d",&y_size);
    printf("Enter number of impulses: ");
    scanf("%d",&h_size);
    x_size=y_size-h_size+1;
    int y[y_size];
    int h[n],x[n];
    if(h_size>x_size)
    {
        n=h_size;
    }
    else
    {
        n=x_size;
    }
	int h[n],x[n];
    for(i=0;i<n;i++)
    {
        h[i]=0;
    }
    printf("Enter output sequences: ");
    for(i=0;i<y_size;i++)
    {
        scanf("%d",&y[i]);
    }
     printf("\nEnter impulse sequences: ");
    for(i=0;i<h_size;i++)
    {
        scanf("%d",&h[i]);
    }

    for(i=0;i<x_size;i++)
    {
        temp=i;
        sum=0;
            for(j=0;j<i;j++)
            {
                sum=sum+x[j]*h[temp];
                temp--;
            }
            x[i]=(int)((y[i]-sum)/h[0]);

    }

    for(i=0;i<x_size;i++)
    {
        printf("%d  ",x[i]);
    }
    return 0;
}
