#include<bits/stdc++.h>
using namespace std;
#define epsilon .001

double f(double x)    
{
     return x*x + (-5)*x + 6 ;
}

int main()
{    
    double a, b, mid;    
    cin>>a>>b; //3 2


    if(f(a)*f(b)>0)       
    {             
        cout<<"Can not determine\n"<<endl;          
    }
    else              
    {
        while (fabs(a-b)>=epsilon)        
        {
            mid=(a+b)/2.0;        

            cout<<"a="<<a<<"     "<<"b="<<b<<"     "<<"c="<<mid<<"      fc="<<f(mid)<<endl;       

            if(f(a)*f(mid)>0)    
            {
                a=mid;    
            }
            else 
            {    
                b=mid;   
            }    
        }
     }
       
    cout<<"The root of the equation is "<<mid<<endl;    
    return 0;    
}
