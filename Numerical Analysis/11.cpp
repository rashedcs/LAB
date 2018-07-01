 #include<bits/stdc++.h>
    using namespace std;

    double newton(double x[], double y[],  int n,  double xn)
    {
             double h=x[1]-x[0];
             double s=1;
             double p=(xn-x[1])/h;
             double sum=y[n-1];

             for(int i=1; i<=n-1; i++)
             {
                    for(int j=0;  j<n-i; j++)
                    {
                          y[j] = y[j+1] - y[j];
                    }
                    s *= (p+i-1)/i;
                    sum += s*y[n-1];
             }
             return sum;
    }

    int main()
    {
              double  xn, x[20], y[20];
              int n;
              scanf("%d",&n);
              for(int i=0; i<n; i++)
              {
                  scanf("%lf %lf",&x[i], &y[i]);
              }
              scanf("%lf",&xn);
              printf("%lf",newton(x, y, n, xn));

              return 0;
    }
