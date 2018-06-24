#include<bits/stdc++.h>
using namespace std;



double solution(double x[10], double y[10],int n)
{
	
    double ans, sum=0;

    double h = x[1] - x[0];

    for(int i=0; i<=n; i++)
    {
        if(i==0 || i==n)
        {
            sum += y[i];
        }
        else
        {
            sum += 2*y[i];
        }
    }
    ans = h/2.0 * (sum);

    return ans;
}


int main()
{
    int n;
    double x0, xn, x[10], y[10]; 

    scanf("%d", &n);
    for(int i=0; i<=n; i++)
    {
	    scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("%lf", solution(x,y,n));
 
    return 0;
}
/** 
Input : 
5
7.47 1.93
7.48 1.95
7.49 1.98
7.50 2.01
7.51 2.03
7.52 2.06

Output :
0.099650 
**/
