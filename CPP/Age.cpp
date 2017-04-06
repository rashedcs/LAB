#include<iostream>
using namespace std;


class age
{
  private:
  int day;
  int month;
  int year;
  public:
 // age():day(1), month(1), year(1) {}
   age()
   {
     day = 0;
     month = 0;
     year = 0;
   }

   void curr()
   {
      cout<<"Current Date  : ";
      time_t t = time(NULL);
      tm *Ptr = localtime(&t); //tm by default class
      day = (Ptr->tm_mday);
      month = (Ptr->tm_mon);
      year = (Ptr->tm_year)+1900;
      cout<<day<<" "<<month<<" "<<year<<endl;
   }


   void get()
   {
     cout<<"Birth Date    : ";
     cin>>day>>month>>year;
   }

   void print(age a1, age a2)
   {
      if(a1.day>a2.day && a1.month>a2.month)
      {
       cout<<"your age is DD-MM-YYYY"<<endl;
       cout<<"\t\t"<<a1.day-a2.day<<"-"<<a1.month-a2.month<<"-"<<a1.year-a2.year;
       cout<<endl<<endl;
      }

      else if(a1.day<a2.day && a1.month<a2.month)
      {
        cout<<"your age is DD-MM-YYYY"<<endl;
        cout<<"\t\t"<<(a1.day+30)-a2.day<<"-"<<(a1.month+11)-a2.month<<"-"<<(a1.year-1)-a2.year;
        cout<<endl<<endl;
      }

      else if(a1.day>a2.day && a1.month<a2.month)
      {
        cout<<"your age is DD-MM-YYYY"<<endl;
        cout<<"\t\t"<<a1.day-a2.day<<"-"<<(a1.month+12)-a2.month<<"-"<<(a1.year-1)-a2.year;
        cout<<endl<<endl;
      }

      else if(a1.day<a2.day && a1.month>a2.month)
      {
        cout<<"your age is DD-MM-YYYY"<<endl;
        cout<<"\t\t"<<(a1.day+30)-a2.day<<"-"<<(a1.month-1)-a2.month<<"-"<<a1.year-a2.year;
        cout<<endl<<endl;
      }

      else if(a1.year<a2.year)
      {
        cout<<"you entered wrong date. plz enter the correct date."<<endl;
      }
   }
};



int main()
{
  age a1, a2, a3;
//for(int i=0; i<3; i++)

  a1.curr();
  a2.get();
  a3.print(a1,a2);

  return 0;
}



/*
#include<iostream>
#include<cmath>
#include <ctime>
using namespace std;

int main()
{

        time_t t = time(NULL);
        tm *timePtr = localtime(&t);

        int day = (timePtr->tm_mday);


    cout << "Date     " <<(timePtr->tm_mday)<<"/"<< (timePtr->tm_mon)+1 <<"/"<< (timePtr->tm_year)+1900<< endl;
    cout << "Time     " << (timePtr->tm_hour)<<":"<< (timePtr->tm_min)<<":"<< (timePtr->tm_sec) << endl;
    cout<<day<<endl;
   return 0;
}

*/


