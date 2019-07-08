#include<stdio.h>
#include<math.h>
int main()
{
    float l=0,h=0,f=0,t=0,i;
    printf("Lower limit of interval:");
    scanf("%f",&l);
    printf("Upper limit of interval:");
    scanf("%f",&h);
    printf("frequency:");
    scanf("%f",&f);
    printf("Sampling period:");
    scanf("%f",&t);
    printf("n\t\t\tx(n)\n");
    for(i=l;i<=20;i++)
    {
        printf("%f\t\t%f\n",i,sin(2*M_PI*f*i*t));
    }
    return 0;
}
