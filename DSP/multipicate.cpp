#include<bits/stdc++.h>
using namespace std;


void evenOdd(float sig[], int num,int ori, float sig2[], int num2,int ori2)
{
    
   // int num2 = num, ori2=(num-ori)+1;
   // int sig2[num2]={};
    /*
    for(int i=0;i<num;i++)
    {
       sig2[i]=sig[i];
    }
    reverse(sig2,sig2+num2);
  
    for(int i=0;i<num;i++)
    {
       sig2[num-i-1]=sig[i];
    }
     */
    
    int size = max(num-ori,num2-ori2) + max(ori,ori2);//Calculate size =left+rig  
    float x1[size]={0},x2[size]={0},res[size]={0};
    
    /* Left Side Calculation */
    int ix=max(ori,ori2)-ori, temp1=ix+num;
    for(int i=ix,j=0; i<temp1; i++,j++)
    {
        x1[i]=sig[j];
    }

    /* Right Side Calculation */
    int kx=max(ori,ori2)-ori2, temp2=kx+num2;
    for(int k=kx,l=0; k<temp2; k++,l++)
    {
        x2[k]=sig2[l];
    }
    
        for(int i=0;i<size;i++){
        res[i]=x2[i]*x1[i];
    }

    cout<<"Added signal with origin "<<max(ori,ori2)<<" \n";
    for(int i=0;i<size;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int num,ori, num2, ori2;
   // cout<<"Size of signal: ";
    cin>>num>>num2;
    float sig[num];
    float sig2[num2];

   // cout<<"Enter signal\n";
    for(int i=0;i<num;i++)
    {
        cin>>sig[i];
    }
   // cout<<"Enter origin of signal 1: ";
    cin>>ori;
    
       // cout<<"Enter signal\n";
    for(int i=0;i<num2;i++)
    {
        cin>>sig2[i];
    }
   // cout<<"Enter origin of signal 1: ";
    cin>>ori2;

    evenOdd(sig,num, ori, sig2,num2, ori2);

    return 0;
}
