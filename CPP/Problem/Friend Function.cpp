 #include<bits/stdc++.h>
 using namespace std;


 class rectangle
 {
    int length, breadth;
  public :
  /* setDimension is a member function */
  void setDimension(int l, int b)
  {
    length = l;
    breadth = b;
  }

   /* a friend function to print the area, it takes an object of
      'rectangle' class as its argument */
   friend void printArea(rectangle rect);
 };


/* printArea is a friend function
   'classname :: ' is not used before the function name
*/
void printArea(rectangle rect)
{
   /* length and breadth can be directly accessed even though
      they are private */
   int area = rect.length * rect.breadth;
   cout << "Area : " << area << endl;
}

int main() {
   rectangle r;
   r.setDimension(9, 7);
   // call friend function with object 'r' as argument
   printArea(r);
   return 0;
}







//Friend class in other class.......

#include <iostream>
using namespace std;

class Rectangle
{
    int width;
    int height;
    
public:
    void display()
    {
        cout << width << " " << height << endl;
    }
    friend class RectangleArea;
};

class RectangleArea: public Rectangle
{
    
public:
    void read_input()
    {
        cin >> width >> height;
    }
    void display()
    {
        cout << width * height;
    } 
};
 



int main()
{
    /*
     * Declare a RectangleArea object
     */
    RectangleArea r_area;
    
    /*
     * Read the width and height
     */
    r_area.read_input();
    
    /*
     * Print the width and height
     */
    r_area.Rectangle::display();
    
    /*
     * Print the area
     */
    r_area.display();
    
    return 0;
}
 

 




















