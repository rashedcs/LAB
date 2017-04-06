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


  clock_t start, terminate, res;

  start = clock();
  for(int i=1; i<1000; i++)
  {
    Hanoi(discs, 'A', 'B', 'C');
  }
  terminate = clock();


  res = (terminate-start)/1000;
  
  cout<<res<<endl;
  return 0;

}

