//https://www.youtube.com/watch?v=MPMRj6PoqaQ
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class ObjectCounter
{

public:
	static int numofobjects;
public:
	ObjectCounter()
	{
		numofobjects ++;
	}
	static void showcount()
	{
		cout<<"Total number of Objects is: "<<numofobjects<<endl;
	}
};

int ObjectCounter ::numofobjects = 0;

int main()
{
	ObjectCounter::showcount();
	ObjectCounter a, b, c;
	cout<<"After instantiating ObjectCounter Class thrice."<<endl;
	ObjectCounter::showcount();
}

