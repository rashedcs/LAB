#include <string.h>
#include <iostream>
#include <map>
#include <utility>

using namespace std;

struct cmp_str 
{
   bool operator()(char const *a, char const *b) 
   {
      return std::strcmp(a, b) < 0;
   }
};

int main()
{
   map<char *, int, cmp_str> Employees;

   // Examples of assigning Map container contents

   // 1) Assignment using array index notation
   Employees["Mike C."] = 5234;
   Employees["Charlie M."] = 3374;

   // 2) Assignment using member function insert() and STL pair
   Employees.insert(std::pair<char *,int>("David D.",1923));
 
   // 3) Assignment using member function insert() and "value_type()"
   Employees.insert(map<char *,int>::value_type("John A.",7582));

   // 4) Assignment using member function insert() and "make_pair()"
   Employees.insert(std::make_pair((char *)"Peter Q.",5328));

   cout << "Map size: " << Employees.size() << endl;

   for( map<char *, int, cmp_str>::iterator ii=Employees.begin(); ii!=Employees.end(); ++ii)
   {
       cout << (*ii).first << ": " << (*ii).second << endl;
   }
}
