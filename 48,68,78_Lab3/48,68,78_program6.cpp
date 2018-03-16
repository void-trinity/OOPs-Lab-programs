// Swap 2 nos. using - 1. Call by val , 2. Call by ref

#include <iostream>
using namespace std;

class Number
{
    public:
    int a,b;
    void get()
    {
        cout<<"Enter two numbers : ";
        cin>>a>>b;
    }
    void show()
    {
        cout<<"a = "<<a<<" , b= "<<b;
    }
    void swap_val();
    void swap_ref(int&,int&);
};

void Number::swap_val()
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
    cout<<"\nCall By Value \nInside Function : ";
    show();
}

void Number::swap_ref(int &a,int &b)
{
    int tmp;
    tmp=a;
    a=b;
    b=tmp;
    cout<<"\n\nCall By Ref \nInside Function : ";
    show();
}

int main()
{
    Number num;
    num.get();
    num.swap_val();
    cout<<"\nOutside Function: ";
    num.show();
    num.swap_ref(num.a,num.b);
    cout<<"\nOutside Function: ";
    num.show();
    return 0;
}
