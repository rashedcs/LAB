#include<bits/stdc++.h>
using namespace std;


class student{
    string name;
    int roll;
    float cgpa;
   public:

     void set_name(string name)
     {
       this->name = name;
     }

     string get_name()
     {
       return name;
     }

     void set_roll(int roll)
     {
       this->roll = roll;
     }

     int get_roll()
     {
        return roll;
     }

     void set_cgpa(float cgpa)
     {
       this->cgpa = cgpa;
     }

     float get_cgpa()
     {
        return cgpa;
     }
};


     bool comp(student ob1, student ob2)
     {
        return ob1.get_cgpa()>ob2.get_cgpa();
     }

int main()
{

  student s[10];
  int n, r;
  string name;
  float c;
  cin>>n;
  for(int i=0; i<n; i++)
  {
    cin>>name>>r>>c;
    s[i].set_name(name);
    s[i].set_roll(r);
    s[i].set_cgpa(c);
  }

    sort(s,s+n,comp);

  /*
  for(int i=0; i<n; i++)
    for(int k=0; k<n-1; k++)
    {
      if(s[i].get_cgpa() < s[k].get_cgpa())   swap(s[i],s[k]);
    }
 */

    cout<<" Name Roll Cgpa "<<endl;
    for(int i=0; i<n; i++)
    {
     cout<<s[i].get_name()<<" "<<s[i].get_roll()<<" "<<s[i].get_cgpa()<<endl;
    }


  return 0;
}
