//Source : http://www.csegeek.com/csegeek/view/tutorials/cpp_lang/cpp_class_obj.php


#include<bits/stdc++.h>
using namespace std;


class rect
{
  int length, width;
  public :
   void setter(int length, int width)
   {
      this->length = length;
      this->width = width;
   }

   int getter()
   {
      return length*width;
   }

   bool comp(rect rt)
   {
     int rect1 = this->getter();
     int rect2 = rt.getter();

     if(rect1>rect2) return true;
     else            return false;
   }


};


int main()
{
  int l, w;
 // cin>>l>>w;
  rect r1, r2;
  r1.setter(5, 6);
  r2.setter(4, 5);
  if(r1.comp(r2)==true) cout<<"Rectangle 1 is greater \n";
  else                  cout<<"Rectangle 2 is greater\n";
  return 0;
}
