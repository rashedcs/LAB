#include<stdio.h>
#include<math.h>
float f(float x,float y)
{
    float f;
    //f=x*x+y;
    f=y-x;
    return f;
}
main()
{
    float x0,y0,y,x,k1,k2,h,xn;
    printf("\nEnter x0,y0,h,xn: ");
    scanf("%f%f%f%f",&x0,&y0,&h,&xn);
    printf("\n  x\t  y\n");
    x=x0;
    y=y0;
    while(x<xn)
    {
        k1=h*f(x,y);
        k2=h*f((x+h),(y+k1));
        y=y+0.5*(k1+k2);
        x=x+h;
        printf("%0.2f\t%0.4f\n",x,y);
    }
    return 0;
}
