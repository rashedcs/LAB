//Reference : http://www.geeksforgeeks.org/check-given-sentence-given-set-simple-grammer-rules/


#include<bits/stdc++.h>
using namespace std;

bool checkSentence(string str)
{
    int len = str.size();

    if (str[0]<'A' || str[0]>'Z' || str[len-1]!='.')
    {
       return false;
    }
    else
    {
        int prev_state=0, curr_state=0;

        for(int index=1; str[index]; index++)
        {
            if(str[index] >= 'A' && str[index] <= 'Z')        curr_state = 0;
            else if(str[index] == ' ')                        curr_state = 1;
            else if(str[index] >= 'a' && str[index] <= 'z')   curr_state = 2;
            else if(str[index]=='.')                          curr_state = 3;

            if((prev_state==curr_state && curr_state!=2) || (prev_state==2 && curr_state==0) )
            {
               return false;
               break;
            }
            else if(curr_state == 3 && prev_state != 1)
            {
               return (str[index + 1] == '\0');
            }
            prev_state = curr_state;
        }
     }
}



int main()
{
    string str;
    while(1)
    {
       getline(cin, str);
       if(checkSentence(str)) printf("Correct\n");
       else                   printf("InCorrect\n");
    }
    return 0;
}
