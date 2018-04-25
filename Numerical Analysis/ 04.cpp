#include<bits/stdc++.h>
using namespace std;
#define EPS 0.001
double f (double x)
{
    return x*x*x + (-2)*x - 5 ;
}
double secant()
{
    double a=2, b=3, c=INT_MIN, p=INT_MAX; //p preserve the c´s value
 

    while(fabs(c-p)>=EPS)
    {
        p = c;
        c=(a*f(b)-b*f(a)) / (f(b)-f(a));
        if(f(c)<0) a=c;
        else       b=c;
        cout<<a<<" "<<b<<endl;
    }
    return c ;
}

int main()
{
    printf("The root is : %.4lf\n",secant());
    return 0;
}
