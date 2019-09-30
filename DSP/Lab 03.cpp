#include<bits/stdc++.h>
using namespace std;



int main()
{
    int sn1,sn2,or1,or2;

   // cout<<"Size of signal: ";
    cin>>sn1;
    sn2=sn1;
    float sig1[sn1],sig2[sn2];

   // cout<<"Enter signal\n";
    for(int i=0;i<sn1;i++){
        cin>>sig1[i];
        sig2[i]=sig1[i];
    }
   // cout<<"Enter origin of signal 1: ";
    cin>>or1;

    reverse(sig2,sig2+sn2);

    or2=(sn1-or1)+1;

    int size=max(sn1-or1,sn2-or2) + max(or1,or2);

    float x1[size]={0},x2[size]={0},odd[size]={0},even[size]={0};
    
    
    int i=max(or1,or2)-or1,j=0;
    int temp=i+sn1;
    for(;i<temp;i++)
    {
        x1[i]=sig1[j];
        j++;
    }

    int k=max(or1,or2)-or2,l=0;
    int temp2=k+sn2;
    for(;k<temp2;k++){
        x2[k]=sig2[l];
        l++;
    }

    for(int i=0;i<size;i++){
        even[i]=(x1[i]+x2[i])/2;
        odd[i]=(x1[i]-x2[i])/2;
    }

   // cout<<"Even components of the signal \n";
    for(int i=0;i<size;i++){
        cout<<even[i]<<" ";
    }
    cout<<endl;

   // cout<<"Odd components of the signal \n";
    for(int i=0;i<size;i++){
        cout<<odd[i]<<" ";
    }
    cout<<endl;

    return 0;
}
