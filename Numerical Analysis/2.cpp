#include<bits/stdc++.h>
using namespace std;
#define epsilon .001

double f(double x)    
{
      return x*x + (-5)*x + 6 ;
}

int main()
{    
    double a, b, c, dx;    
    cin>>a>>b; //3 2

    if(f(a)*f(b)>0)       
    {             
            cout<<"Can not determine\n"<<endl;          
    }
    else              
    {
	    cout<<"a"<<"\t\t\t"<<"b"<<"\t\t\t"<<"c"<<"\t\t\t"<<"f(c)"<<endl;
	    while (fabs(b-a)>=epsilon)        
	    {
          dx = b-a;
          c = a + (dx*=0.5);        

          cout<<a<<"\t\t\t"<<b<<"\t\t\t"<<c<<"\t\t\t"<<f(c)<<endl;       

          if(f(a)*f(b)<0)
          {
              b=c;    
          }
          else 
          {    
              a=c;   
          }    
	    }
     }
       
    cout<<"The root of the equation is "<<c<<endl;    
    return 0;    
}
