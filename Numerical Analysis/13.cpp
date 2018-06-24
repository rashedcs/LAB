#include<bits/stdc++.h>
using namespace std;


double f(double x)
{
      return(1/(1+x));
}

double solution(double x0, double xn, double h)
{
    int n = (xn-x0)/h;
    double x[10], y[10];

    for(int i=0; i<=n; i++)
    {
        x[i] = x0+i*h;
        y[i] = f(x[i]);
    }

    double ans, sum = 0;

    for(int i=0; i<=n; i++)
    {
        if(i==0 || i==n)
        {
          sum += y[i];
        }
        else if(i%2==1)
        {
            sum += 4*y[i];
        }
        else
        {
            sum += 2*y[i];
        }
    }
    ans = h/3*(sum);

    return ans;
}


int main()
{
    double x0, xn, h; 

    scanf("%lf %lf %lf",&x0, &xn, &h);
    printf("Final integration is %lf", solution(x0, xn, h));
 
    return 0;
}

/**
Input : 2 4 0.5
Output : 0.510847 
**/
