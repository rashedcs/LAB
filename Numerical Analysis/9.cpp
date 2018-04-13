    #include<bits/stdc++.h>
    using namespace std;


    double newton(double x[], double y[],  int n,  double f)
    {
             double h=x[1]-x[0];
             double s=1;
             double p=(f-x[0])/h;
             double yo=y[0];

             for(int i=1; i<=n-1; i++)
             {
                    for(int j=0;  j<n-i; j++)
                    {
                          y[j] = y[j+1] - y[j];
                    }
                    s  *=  (p-i+1)/i;
                    yo += s*yo;
             }
             return yo;
    }


    int main()
    {
              double  f, x[20], y[20];
              int n;
              scanf("%d",&n);
              for(int i=0; i<n; i++)
              {
                  scanf("%lf %lf",&x[i], &y[i]);
              }
              scanf("%lf",&f);
              printf("%lf",newton(x, y, n, f));

              return 0;
    }
