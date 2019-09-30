#include<bits/stdc++.h>
using namespace std;


void evenOdd(float sig[], int num,int ori)
{
    
    int num2 = num, ori2=(num-ori)+1;
    int sig2[num2]={};
    /*
    for(int i=0;i<num;i++)
    {
       sig2[i]=sig[i];
    }
    reverse(sig2,sig2+num2);
   */
    for(int i=0;i<num;i++)
    {
       sig2[num-i-1]=sig[i];
    }
    
    int size = max(num-ori,num2-ori2) + max(ori,ori2);//Calculate size =left+rig  
    float x1[size]={0},x2[size]={0},odd[size]={0},even[size]={0};
    
    int ix=max(ori,ori2)-ori,j=0;
    int temp1=ix+num;
    for(int i=ix;i<temp1;i++)
    {
        x1[i]=sig[j];
        j++;
    }

    int kx=max(ori,ori2)-ori2,l=0;
    int temp2=kx+num2;
    for(int k=kx; k<temp2; k++)
    {
        x2[k]=sig2[l];
        l++;
    }
    
    for(int i=0;i<size;i++)
    {
        even[i]=(x1[i]+x2[i])/2;
        odd[i]=(x1[i]-x2[i])/2;
    }
   // cout<<"Even components of the signal \n";
    for(int i=0;i<size;i++)
    {
        cout<<even[i]<<" ";
    }
    cout<<endl;

   // cout<<"Odd components of the signal \n";
    for(int i=0;i<size;i++){
        cout<<odd[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int num,ori;
   // cout<<"Size of signal: ";
    cin>>num;
    float sig[num];

   // cout<<"Enter signal\n";
    for(int i=0;i<num;i++)
    {
        cin>>sig[i];
    }
   // cout<<"Enter origin of signal 1: ";
    cin>>ori;

    evenOdd(sig,num, ori);

    return 0;
}
/* Link : http://ideone.com/lUkL3n */
