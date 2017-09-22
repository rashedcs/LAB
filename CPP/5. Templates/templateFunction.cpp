#include<bits/stdc++.h>
using namespace std;

template<class T>
void swapargs(T a, T b)
{
  T temp = a;
  a = b;
  b = temp;
  cout<<a<<" "<<b<<endl;
}


int main()
{
  int a, b;
  float x, y;
  string str1, str2;

  swapargs(2,3);
  swapargs(2.5,3.5);
  swapargs("Rashed","Bash");

  return 0;
}


