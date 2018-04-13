    #include<bits/stdc++.h>
    using namespace std;

    double lagrange(double x[], double y[],  int n,  double xi)
    {
            double num, dem, result=0; 
         
            for(int i=0; i<n; i++)
            {
                num=dem=1;
                for(int j=0; j<n; j++)
                {
                    if(j!=i)
                    {
                        num *= (xi-x[j]);
                        dem *= (x[i]-x[j]);
                    }
                }
                result += y[i]*(num/dem);
            }
            return result;
    }

    int main()
    {
            double  xi, x[20], y[20];
            int n;
            scanf("%d",&n);
            for(int i=0; i<n; i++)
            {
                scanf("%lf %lf",&x[i], &y[i]);
            }
            scanf("%lf",&xi);
            printf("%lf",lagrange(x, y, n, xi));

            return 0;
    }
