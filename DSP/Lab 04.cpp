
#include<iostream>

using namespace std;

int main()
{
    int no_of_value,dif_point;
    char check='y';

    cout<<"How many no of values of x & y\n";
    cin>>no_of_value;

    float x[no_of_value],y[no_of_value];

    cout<<"Enter values of x\n";
    for(int i=0;i<no_of_value;i++){
        cin>>x[i];
    }

    cout<<"Enter values of y\n";
    for(int i=0;i<no_of_value;i++){
        cin>>y[i];
    }


    while(check=='y' || check=='Y'){

        cout<<"Enter differentiation point\n";
        cin>>dif_point;
        cout<<"Value of differentiation at point "<<dif_point<<" is ";
        cout<<(y[dif_point]-y[dif_point-1])/(x[dif_point]-x[dif_point-1])<<endl;
        cout<<"Want to differentiate again(y/n): ";
        cin>>check;
    }


    return 0;
}
