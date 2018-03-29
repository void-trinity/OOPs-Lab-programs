#include<iostream>
#include<cmath>
using namespace std;

class Prog
{
int a,d;//AP,GP,HP
int t;
int n;
public:
    Prog()
    {
        a=0;d=0;
        t=0;n=0;
    }
    void input(int i){
    switch(i)
    {
      case 1:
         cout<<"Enter first term and common difference of AP :";
          cin>>a>>d;
           break;
      case 2:
        cout<<"Enter first term and common ratio of GP :";
          cin>>a>>d;
           break;
      case 3:
        cout<<"Enter first term and common difference of HP's corresponding AP :";
          cin>>a>>d;
           break;
    }
    }
    void nterm(int i)
    {
    cout<<"Enter the term to be calculated (Nth):";
    cin>>n;
        switch(i)
    {
      case 1:
        t=a+(n-1)*d;
           break;
      case 2:
        t=a*pow(d,n-1);
           break;
      case 3:
        t=a+(n-1)*d;
           break;
    }
    }
    void print(int i)
    {
        switch(i)
    {
      case 1:
         cout<<n<<"th"<<"term of AP is :"<<t<<endl;

           break;
      case 2:
       cout<<n<<"th"<<"term of GP is :"<<t<<endl;
           break;
      case 3:
        cout<<n<<"th"<<"term of HP is :"<<"1/"<<t<<endl;
           break;
    }
    }
};
int main()
{ int ch;
cout<<"16115068 Sadanand Vishwas \n\n";
Prog p1;
while(1){
cout<<"1.AP\n2.GP\n3.HP\n4.Exit\n";
cout<<"Select your choice :";
cin>>ch;
if(ch>=4 ||ch<=0)
    break;
p1.input(ch);p1.nterm(ch);p1.print(ch);
}


    return 0;
}

