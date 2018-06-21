/* Euler Method */

#include<bits/stdc++.h>
using namespace std;

double fun(double x, double y)
{
    return x+y;
}

void euler(float x0, float y0, float h, float xn)
{
    double x=x0;
    double y=y0;
    double k;
    while(x<=xn)
    {
        k=h*fun(x,y);
        y=y+k;
        x=x+h;
    }
    printf("%0.3f\t%0.3f\n",x,y);
}

int main()
{
    double x0, y0, xn, h, k;
    
    printf("\nEnter x0, y0, h, xn: ");
    scanf("%lf %lf %lf %lf",&x0,&y0,&h,&xn);
    
    euler(x0, y0, h, xn);
    return 0;
}
