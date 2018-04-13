#include<bits/stdc++.h>
using namespace std;
#define EPS 0.001
double f (double x)
{
    return x*x*x + (-2)*x - 5 ;
}
double secant()
{
    double a=2, b=3, c; //x0=a, x1=b;
 
    while(fabs(b-a)>=EPS)
    {
        c = (f(b)*a-f(a)*b) / (f(b)-f(a)) ;
        a=b;
        b=c;
    }
    return c ;
}

int main()
{
    printf("The root is : %.4lf\n",secant());
    return 0;
}


//Daught : https://ideone.com/CSfIPe
