#include<bits/stdc++.h>
using namespace std;
#define EPS 0.001

double f (double x)
{
    return x*x*x + (-2)*x - 5;
}
double diff(double x)
{
    return 3*x*x + (-2) ;
}

double newrap(double x0)
{
    double x1;
 
    while(fabs(x1-x0)>=EPS)
    {
        x1 = x0 - (f(x0)/diff(x0)) ;
        x0 = x1 ;
    }
    return x0;
}

int main()
{
    printf("The root is : %.6lf\n",newrap(2));
    return 0;
}

