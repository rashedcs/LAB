#include<stdio.h>
int main()
{
    int m,n,x[100]={0},y[100]={0},z[100]={0},i;
    printf("Enter the size of 1st sequence:\n");
    scanf("%d",&m);
    printf("Enter the size of 2nd sequence:\n");
    scanf("%d",&n);
    printf("Enter 1st sequence:");
    for(i=0;i<m;i++)
        scanf("%d",&x[i]);
        printf("Enter 2nd sequence:");
    for(i=0;i<n;i++)
        scanf("%d",&y[i]);
        printf("The added sequence is:");
    if(m>=n)
    {
        for(i=0;i<m;i++)
            z[i]=x[i]+y[i];
            for(i=0;i<m;i++)
                printf("%d ",z[i]);
    }
    if(m<n)
    {
        for(i=0;i<n;i++)
            z[i]=x[i]+y[i];
            for(i=0;i<n;i++)
                printf("%d ",z[i]);
    }
return 0;
}
