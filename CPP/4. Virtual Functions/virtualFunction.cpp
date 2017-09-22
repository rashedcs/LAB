#include<bits/stdc++.h>
using namespace std;



class Base
{
  public:
  virtual void show()
  {
    cout << "Base class";
  }
};

class Derived:public Base
{
  public:
  void show()
  {
    cout << "Derived Class";
  }
};


int main()
{
 ios::sync_with_stdio(false);
 Base* b;       //Base class pointer
 Derived d;     //Derived class object
 b = &d;
 b->show();     //Late Binding Ocuurs
}



