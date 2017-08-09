#include<bits/stdc++.h>
using namespace std;



void recognize(string str[], string input)
{
       int len, flag;

        len = input.size();
        if((input[0]>='0' && input[0]<='9') && ((input[1])>='a' && input[1]<='z'))
        {
            flag=10;
            goto out;
        }

        else if(input[0]>='0' && input[0]<='9')
        {
            for(int i=0; i<len; i++)
            {
                if(input[i]=='.')
                {
                        flag=2;
                        break;
                }
                else
                {
                        flag=1;
                }
            }
        }

        else if((input[0]>='a'&&input[0]<='z') || (input[0]>='A'&&input[0]<='Z') || input[0]=='_')
        {
            for(int i=0; i<32; i++)
            {
                 if(str[i]==input)
                 {
                        flag=3;
                        break;
                 }
                 else
                 {
                       flag=4;
                 }
            }
        }
        out:
            if(flag==1)
                puts("Integer Constant.");
            else if(flag==2)
                puts("Floating point Constant.");
            else if(flag==3)
                puts("Keyword.");
            else if(flag==4)
                puts("Identifier.");
            else if(flag==10)
                puts("Invalid.");
}




int main()
{
        ios::sync_with_stdio(false);
        string input;
        string str[32]={"auto","break","case","char","const","continue","default","do","double","else",
        "enum","extern","float","for","goto","if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};


           while(input!="$")
           {
                    cin>>input;
                    recognize(str, input);

           }
           return 0;
    }
