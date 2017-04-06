#include<bits/stdc++.h>
  using namespace std;


  class Birthday
  {
    int month;
    int day;
    int year;
	public:
		Birthday(int m, int d, int y)
        {
          month = m;
	      day = d;
	      year = y;
        }
        void printDate()
        {
	      cout << month << "/" << day << "/" << year <<endl;
        }
   };



   class People
   {
       string name;
       Birthday dataOfBirth;

    public:
       People(string x, Birthday bo) : name(x), dataOfBirth(bo)
       {

       }

       void printInfo()
       {
	     cout << name << "was born on";
	     dataOfBirth.printDate();
       }
   };






   int main()
   {
	  Birthday birthObj(12,28,1986);
	  People buckyRoberts("Bucky the King", birthObj);

	  buckyRoberts.printInfo();
	  return 0;
   }
