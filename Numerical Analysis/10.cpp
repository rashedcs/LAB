    #include<bits/stdc++.h>
    using namespace std;

    double lagrange(double x[], double y[],  int n,  double xi)
    {
            double num, dem, result=0; 
            
            for(int i=0; i<n; i++)
            {
                num=dem=1;
                /* Determine Li */
                for(int j=0; j<n; j++)
                {
                    if(i!=j)
                    {
                        num *= (xi-x[j]); 
                        dem *= (x[i]-x[j]);
                    }
                }
                
                /*Sum up individual Li*/
                result += y[i]*(num/dem);    //sum = L1*y(1) + L2*y(2) + L3*y(3) + L4*y(4)
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
