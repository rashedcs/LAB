#include<bits/stdc++.h>
using namespace std;



int main()
{
        char num[10];
        int ch,i,ln;
        char c[32][10]={"auto","break","case","char","const","continue","default","do","double","else",
        "enum","extern","float","for","goto","if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union","unsigned","void","volatile","while"};

        cout<<"\nEnter '$' to quite or enter a word:";
        cin>>num;
        if(num[0]=='$')
		exit(0);
        ln=strlen(num);
        if((num[0]>='0' && num[0]<='9') && (num[1]>='a' && num[1]<='z'))
            {
                ch=10;
                goto out;
            }
            if(num[0]>='0' && num[0]<='9')
            for(i=0;i<ln;i++)
                {
                    if(num[i]=='.')
                        {
                            ch=2;
                            break;
                        }
                        else
                            ch=1;
                }
                if((num[0]>='a' && num[0]<='z') || (num[0]>='A' && num[0]<='Z') || num[0]=='_')
                for(i=0;i<32;i++)
                    {
                        if(strcmp(c[i],num)==0)
                            {
                                ch=3;
                                break;
                            }
                            else
                                ch=4;
                    }
                    out:
                        if(ch==1)
                            cout<<"\nInteger Constant.";
                        else if(ch==2)
                            cout<<"\nFloating point Constant.";
                        else if(ch==3)
                            cout<<"\nKeyword.";
                        else if(ch==4)
                            cout<<"\nIdentifier.";
                        else if(ch==10)
                            cout<<"\nInvalid.";

                        return main();
    }
