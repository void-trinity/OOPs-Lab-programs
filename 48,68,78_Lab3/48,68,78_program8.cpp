// Fibonacci Series using Class

#include <iostream>
using namespace std;

class Fibonacci
{
    public:
    int a,b,c;
    void genFibo();
};

void Fibonacci :: genFibo()
{
    int i,n;
    cout<<"Enter no. of Terms : ";
    cin>>n;
    cout<<"Fibonacci Series   : ";
    a=0,b=1;
    cout<<a<<" "<<b<<" ";
    for(i=0;i<n-2;i++)
    {
        c=a+b;
        cout<<c<<" ";
        a=b;
        b=c;
    }
}

int main()
{
    Fibonacci f1;
    f1.genFibo();
    return 0;
}
