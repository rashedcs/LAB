#include<iostream>

using namespace std;

int main()
{
    int sn1,sn2,or1,or2;

    cout<<"Size of signal 1 & 2: ";
    cin>>sn1>>sn2;

    float sig1[sn1],sig2[sn2];

    cout<<"Enter signal 1\n";
    for(int i=0;i<sn1;i++){
        cin>>sig1[i];
    }
    cout<<"Enter origin of signal 1: ";
    cin>>or1;

    cout<<"Enter signal 2\n";
    for(int i=0;i<sn2;i++){
        cin>>sig2[i];
    }

    cout<<"Enter origin of signal 2: ";
    cin>>or2;

    int size=max(sn1-or1,sn2-or2)+max(or1,or2);

    float x1[size]={0},x2[size]={0},res[size]={0};
    int i=max(or1,or2)-or1,j=0;
    int temp=i+sn1;
    for(;i<temp;i++){
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
        res[i]=x2[i]*x1[i];
    }

    cout<<"Multiplied signal with origin "<<min(or1,or2)<<" \n";
    for(int i=0;i<size;i++){
        cout<<res[i]<<" ";
    }
    cout<<endl;

    return 0;
}
