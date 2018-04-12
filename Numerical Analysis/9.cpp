#include<stdio.h>
#include<math.h>

int main()
{
    int i,j,k,n;
    float h,x,yp,p,nr=1.0,dr=1.0,ax[40],ay[40],dif[40][10];
    printf("enter the value of n:");
    scanf("%d",&n);
    printf("enter the value of x and y:");
    for(i=0;i<n;i++)
    {
        scanf("%f %f",&ax[i],&ay[i]);
    }
    printf("enter the value of x for which y is wanted:");
    scanf("%f",&x);

  h=ax[1]-ax[0];
  p=(x-ax[0])/h;
  yp=ay[0];

for(i=0;i<n;i++)
    dif[i][1]=ay[i+1]-ay[i];
for(j=2;j<n;j++)
for(i=0;i<=n-j;i++)
dif[i][j]=dif[i+1][j-1]-dif[i][j-1];

for(k=1;k<n;k++)
{
    nr *=p-k+1;
    dr *=k;
    yp +=(nr/dr)*(dif[0][k]);
}
printf("when x=%.2f       y=%.4f",x,yp);
return 0;

}
