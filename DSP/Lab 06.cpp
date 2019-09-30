#include<stdio.h>

int main()
{
    int i,j,n,x1_size,y_size,x2_size,sum=0,temp;
    printf("Enter number of first signal samples: ");
    scanf("%d",&x1_size);
    printf("Enter number second signal samples: ");
    scanf("%d",&x2_size);



    if(x1_size>x2_size)
    {
        y_size=x1_size;
    }
    else
    {
        y_size=x2_size;
    }
    int x1[y_size],x2[y_size];
    int y[y_size];
    for(i=0;i<y_size;i++)
    {
        y[i]=0;
        x1[i]=0;
        x2[i]=0;
    }
    printf("Enter first sequences: ");
    for(i=0;i<x1_size;i++)
    {
        scanf("%d",&x1[i]);
    }
     printf("\nEnter impulse sequences: ");
    for(i=0;i<x2_size;i++)
    {
        scanf("%d",&x2[i]);
    }

    for(i=0;i<y_size;i++)
    {
        temp=i;
        sum=0;
            for(j=0;j<y_size;j++)
            {
                sum=sum+x1[j]*x2[temp];
                temp--;
                if(temp<0)
                {
                    temp=y_size-1;
                }
            }
            y[i]=sum;

    }

    for(i=0;i<y_size;i++)
    {
        printf("%d  ",y[i]);
    }
    return 0;
}
