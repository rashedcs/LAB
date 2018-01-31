#include<bits/stdc++.h>
using namespace std;
#define epsilon .001

double f(double x)    
{
     return (x*x*x - 2*x - 5);
}

int main()
{    
    double a, b, c;    
    cin>>a>>b; //3 2

    if(f(a)*f(b)>0)       
    {             
            cout<<"Can not determine\n"<<endl;          
    }
    else              
    {
	    cout<<"a"<<"\t\t\t"<<"b"<<"\t\t\t"<<"c"<<"\t\t\t"<<"f(c)"<<endl;
	    while (fabs(a-b)>=epsilon)        
	    {
    		c=(a+b)/2.0;        
    
    		cout<<a<<"\t\t\t"<<b<<"\t\t\t"<<c<<"\t\t\t"<<f(c)<<endl;       
    
		//if(f(c)<0) f(c) is negative then a=c  
    		if (f(a)*f(c)>0)    
    		{
    		    a=c;    
    		}
    		else 
    		{    
    		    b=c;   
    		}    
	    }
     }
       
    cout<<"The root of the equation is "<<c<<endl;    
    return 0;    
}
