#include<bits/stdc++.h>
using namespace std;

double f(double x, double y)
{
    return (x-y)/(x+y);
}

void ronga(float x0, float y0, float h, float xn)
{
    double x=x0;
    double y=y0;
    double k1, k2;

    while(x<=xn)
    {
        k1=h*f(x,y);
        k2=h*f((x+h),(y+k1));
        y=y+0.5*(k1+k2);
        x=x+h;
        printf("%0.2f\t%0.4f\n",x,y);
    }
}

int main()
{
    double x0, y0, xn, h, k;
    scanf("%lf %lf %lf %lf",&x0,&y0,&h,&xn);
    
    ronga(x0, y0, h, xn);
    return 0;
}
