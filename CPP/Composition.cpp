//Example of Cricket Score
    #include<bits/stdc++.h>
   using namespace std;

   class ball
   {
     char type;
     int run;
     char Wicket;

    public:
      void put()
       {
         cin>>type>>run>>Wicket;
       }

       char isType()
       {
          return type;
       }

      int isRun()
       {
          return run;
       }

       char isWicket()
       {
          return Wicket;
       }
    };



   class innings
   {

    public:
      int trun;
      int twicket;
      int tball;
      ball object[20];

   public:
       innings()
       {
          trun=twicket=tball=0;
       }

       void set_ball(ball ob, int i)
       {
          object[i]=ob;            //trun +=obj.isRun();
          if(ob.isRun()!=0)        trun +=ob.isRun();
          if(ob.isWicket()=='o')   twicket++;
          if(ob.isType()=='v')     tball++;
       }

       bool isOver()
       {
          return twicket==5 || tball == 5;
       }
    };


    int main()
    {
        innings A,B;
        ball tmp;


        cout <<"Input for team 1:\n";
        for(int i=0; i<20; i++)
        {
           cout<< A.trun <<"/"<<A.twicket<<" - "<<A.tball<<" : ";
           tmp.put();
           A.set_ball(tmp,i);

           if(A.isOver())
           {
               cout<<"Team 1 total score:"<< A.trun <<"/"<<A.twicket<<" - "<<A.tball;
               break;
           }
        }

        cout <<"\n\nInput for team 2:\n";
        for(int i=0; i<20; i++)
        {
           cout<< B.trun <<"/"<<B.twicket<<" - "<<B.tball<<" : ";
           tmp.put();
           B.set_ball(tmp,i);

           if(B.trun>A.trun) break;
           if(B.isOver())
           {
               cout<<"Team 1 total score:"<< B.trun <<"/"<<B.twicket<<" - "<<B.tball;
               break;
           }
        }

        if(A.trun>B.trun) cout<<"A is win"<<endl;
        else              cout<<"B is win "<<endl;

        return 0;
     }
