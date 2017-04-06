#include<bits/stdc++.h>
using namespace std;


class employee
{
   char designation[30];
   char name[15];
   int id;
   int salary;
   public:
   void set_designation(char*d)
   {
     strcpy(designation,d);
   }
   void set_name(char*n)
   { 
      strcpy(name,n);
   }
   void set_id(int i)
   {
      id=i;
   }
   void set_salary(int s)
   {
      salary=s;
   }
   char *get_designation()
   {
     return designation;
   }
   char *get_name()
   {
      return name;
   }
 
   int get_id()
   { 
      return id;
   }
 
   int get_salary()
   { 
     return salary;
   }
};



class swd:  public employee
{

};



class tl:public employee
{
   int totalsalary;
    public:
    /*
    void total_salary_of_tl(int b, int pv)
    {
      totalsalary=b+(8*b)/100+(5*pv)/100;
    }
    */
    int get_total_salary_of_tl(int b, int pv)
    {
        return b+(8*b)/100+(5*pv)/100;
    }
};

class pm:public employee
{int totalsalary;
    public:
    /*
    void total_salary_of_pm(int c,int pv)
    {
      totalsalary=c+(20*c)/100+(10*pv)/100;
    }
    */
    int get_total_salary_of_pm(int c, int pv)
    {
        return c+(20*c)/100+(10*pv)/100;
    }
};


int main()
{ int a,v;
 swd s1,s2,s3;
 tl t;
 pm p;
 
 s1.set_name("MR.JONY");
 s2.set_name("MR.RONY");
 s3.set_name("MR.RUNA");
 t.set_name("MR.RANA");
 p.set_name("MR.RINA");
 
  s1.set_id(1234);
 s2.set_id(3456);
 s3.set_id(5678);
 t.set_id(8901);
 p.set_id(1267);
 
 s1.set_designation("SOFTWARE DEVELOPER");
 s2.set_designation("SOFTWARE DEVELOPER");
 s3.set_designation("SOFTWARE DEVELOPER");
 t.set_designation("TEAM LEADER");
 p.set_designation("PROJECT MANAGER");
 
 cout<<"give swd salary";
 cin>>a;
 s1.set_salary(a); //s1.set_salary(2000)
 s2.set_salary(a); //s1.set_salary(2000)
 s3.set_salary(a);
 
 cout<<"give project value";
 cin>>v;

 //t.total_salary_of_tl(s1.get_salary(),v);
 //t.set_salary(t.get_total_salary_of_tl());


 t.set_salary( t.get_total_salary_of_tl(s1.get_salary(),v) );
 p.set_salary( p.get_total_salary_of_pm(s1.get_salary(),v) );

 cout<<"INFORMATION OF ALL EMPLOYEES"<<endl;
 cout<<"#"<<s1.get_id()<<"   "<<s1.get_name()<<"  "<<s1.get_designation()<<"  "<<s1.get_salary()<<endl;
 cout<<"#"<<s2.get_id()<<"   "<<s2.get_name()<<"  "<<s2.get_designation()<<"  "<<s2.get_salary()<<endl;
 cout<<"#"<<s3.get_id()<<"   "<<s3.get_name()<<"  "<<s3.get_designation()<<"  "<<s3.get_salary()<<endl;
 cout<<"#"<<t.get_id()<<"   "<<t.get_name()<<"  "<<t.get_designation( )<<"    "<<t.get_salary()<<endl;
 cout<<"#"<<p.get_id()<<"   "<<p.get_name()<<"  "<<p.get_designation()<<"     "<<p.get_salary()<<endl;
 return 0;
}
