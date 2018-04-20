
   //Article : http://thecodersportal.com/knapsack-greedy/
    #include<bits/stdc++.h>
    using namespace std;

    int n;


    bool comp(const pair<int, int> &a, const pair<int, int> &b)
    {
        //return (double)(a.first/a.second) > (double)(b.first/b.second);
          double r1 =  (double)a.first / a.second;
          double r2 =  (double)b.first / b.second;
          return r1 > r2;
    }



    void fractionalKnapsack(pair<int, int>P[], int W)
    {
        sort(P, P+n, comp);

       //double curWeight = 0.0;  // Current weight in knapsack
       float pro = 0.0; // Result (value in Knapsack)

       // Looping through all Items
       for (int i=0; i<n; i++)
       {
         // If adding Item won't overflow, add it completely
          if(P[i].second <= W)
          {
             pro += P[i].first;
             W   -= P[i].second;
          }

          // If we can't add current Item, add fractional part of it
          else
          {
             cout<<pro<<endl;
             pro += P[i].first* ((double) (W) / P[i].second);
             break;
          }
       }
       printf("Maximize profit is : %lf\n",pro);
    }




input :
3 50
60 10
100 20
120 30

Output :
240



//Using structure : http://ideone.com/xmkIoy

//Traditional  : http://ideone.com/cmYtTV






