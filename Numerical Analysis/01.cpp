#include<bits/stdc++.h>
#define epsilon .001
 
double f(double x) 
{
  return (x*x*x - 2*x - 5);
}
 
double bisection()
{
	 double c, a=2, b=3; 
	
	 if(f(a)*f(b)>0) 
	 { 
            printf("Can not determine\n"); 
	 } 
	 else
	 {
            while(fabs(a-b)>=epsilon) 
	    {
 		    c=(a+b)/2.0;     
		    //cout<<a<<"\t\t\t"<<b<<"\t\t\t"<<c<<"\t\t\t"<<f(c)<<endl;       
		    if(f(c)<0)   a=c;  //if (f(a)*f(c)>0) a=c
 		    else         b=c; 
	    }
            return c ;
	 }
}
 
int main()
{
	 printf("The root is : %.4lf\n",bisection());
 	 return 0;
}
