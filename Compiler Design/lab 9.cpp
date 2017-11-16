   #include<bits/stdc++.h>
   using namespace std;


   void prefex2postfix(string s)
   {
      stack<char>st;
      for(int i=0; i<s.length(); i++)
      {
          if(isdigit(s[i]) || isalpha(s[i]))
          {
               cout<<s[i];
          }
          else if( s[i]==')' )
          {
             while(st.top()!='(')
             {
                cout<<st.top();
                st.pop();
             }
             st.pop();
          }
          else
          {
            st.push(s[i]);
          }
       }
    }


  int main()
  {
     ios::sync_with_stdio(false);
     string str;

     while(cin>>str)
     {
        prefex2postfix(str);
        cout<<endl;
     }

     return 0;
  }
