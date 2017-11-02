//Problem Name : Write a C++ program to find out  keyword from a C/C++ program.

//Solution :
#include<bits/stdc++.h>
using namespace std;


bool isKeyword(string buffer)
{
    string keywords[32] = {"auto","break","case","char","const","continue","default", "int",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","while"};
    int flag = 0;

    for(int i=0; i<32; i++)
    {
        if(keywords[i]==buffer)
        {
            flag = 1;
            break;
        }
    }
    return flag;
}



int main()
{
    ios::sync_with_stdio(false);

    ifstream inFile; //Declares a file stream object
    string word, fileName;

    cout<<"Please enter the file name ";
    getline(cin,fileName);

    inFile.open(fileName.c_str());

    while(!inFile.eof())
    {
        inFile >> word;
        if(isKeyword(word))
        {
           cout<<word<<endl;
        }
    }
    inFile.close();
    //cin.get();
    return 0;
}
