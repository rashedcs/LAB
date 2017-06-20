#include<bits/stdc++.h>
using namespace std;

/*
bool cmp(const pair<int, int>  &p1, const pair<int, int> &p2)
{
    return p1.second < p2.second;
}
*/

int main()
{
    ios::sync_with_stdio(false);

    map<int, int> m;

    for(int i=0; i<10; i++)
    {
       m[i] = 5*i;
    }

    vector<pair<int, int> > v(m.begin(), m.end());

    /*
        vector<pair<int, int> > v;
        copy(m.begin(), m.end(), back_inserter(v));
        sort(v.begin(), v.end(), cmp);
    */

    for(int i=0; i<v.size(); i++)
    {
        cout<<v[i].first<< " : " <<v[i].second<<endl;
    }

    return 0;
}


