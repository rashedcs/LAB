#include<bits/stdc++.h>
using namespace std;



void Hanoi(int m, char a, char b, char c)
{
  if(m == 1)
  {
    cout << "Move disc " << m << " from " << a << " to " << c << endl;
  }

  else
  {
    Hanoi(m-1, a,c,b);
    cout << "Move disc " << m << " from " << a << " to " << c << endl;
    Hanoi(m-1,b,a,c);
  }
}


int main()
{

   int discs;

   cout<<"Enter the number of discs: "<<endl;
   cin >> discs;

   Hanoi(discs, 'A', 'B', 'C');

   return 0;

}
