#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int main()
{
    int n,i,f;
    char s[100];

    while(scanf("%s",&s)!=EOF){
        f = 0;
        n = strlen(s);

        if((s[0]=='*' || s[n-1]=='*') ||
           (s[0]=='/' || s[n-1]=='/') ||
           (s[0]=='+' || s[n-1]=='+') ||
           (s[0]=='-' || s[n-1]=='-')){
                f = 1;
           }
        else{
            for(i=1;i<n-1;i++){
                if((s[i]=='*' || s[i]=='+' ||
                   s[i]=='/' || s[i]=='-') &&
                   (s[i+1]=='*' || s[i+1]=='+' ||
                   s[i+1]=='/' || s[i+1]=='-')){
                        f = 1;
                        break;
                   }
            }
        }

        if(f==0){
            printf("Valid\n");
        }
        else{
            printf("Invalid\n");
        }

    }

    return 0;
}
