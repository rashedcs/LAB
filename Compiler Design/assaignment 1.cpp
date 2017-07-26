#include<bits/stdc++.h>
using namespace std;


int main()
{
     ios::sync_with_stdio(false);
     while(1)
     {
        string str[63]={"asm","auto","bool","break","case","catch","char","class","const","const_cast","continue","default","delete","do","double","dynamic_cast",
        "else","enum","explicit","export","extern","false","float","for","friend","goto","if","inline","int","long","mutable","namespace",
        "new","operator","private","protected","public","register","reinterpret_cast","return","short","signed","sizeof","static","static_cast",
        "struct","switch","template","this","throw","true","try","typedef","typeid","typename","union","unsigned","using","virtual",
        "void","volatile","wchar_t","while"};
        string input;


        printf("\n Enter the string : ");
        cin>>input;

        for(int i=0; i<63; i++)
        {
           if(str[i]==input)
           {
             flag=1;
             break;
           }
        }

        if(flag==0)
        printf("\n It is not a keyword in C/C++ language.\n");
        else
        printf("\n It is a keyword in C/C++ language.\n");
    }
    return 0;
}
