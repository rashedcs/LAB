#include<bits/stdc++.h>
   using namespace std;


   template <class T>
   class stream
   {
    T  x, y;
	public:

		void setter(T a, T b)
		{
		  x = a;
		  y = b;  //cout << "stream<T>::f()"<< endl ;
		}

		T getter()
		{
		   return x+y;
		}
  };



  int main()
  {
      ios::sync_with_stdio(false);

	     stream<int> si ;
	     //stream<char> sc ;

	    si.setter(2,5) ;
	    cout<<si.getter()<<endl ;

     return 0;
  }










//Using Constructure

#include<bits/stdc++.h>
 using namespace std;


 template<class T>

 class my
 {
    T  a, b;

  public:

    my(T x)
    {
       a = x;
    }

    T setter(T x, T y)
    {
      return a = x+y;
    }

    void show()
    {
       cout<<a<<endl;
    }
 };


 int main()
 {
    ios::sync_with_stdio(false);

    my<int> ob1(10);
    my<double> ob2(10.25);
    my<string> ob3("Aish");

    ob1.show();
    ob2.show();
    ob3.show();


    ///Setter Function

     ob3.setter("Aish ","Like");
     ob3.show();

    return 0;
 }
