#include<iostream>
using namespace std;

class Complex
{
int real,imag;
public:
    Complex(int r=0,int i=0){
    real=r;imag=i;
    }
    void display(){
    cout<<real<<" +i "<<imag<<endl;
    }
    Complex operator +(Complex &obj)
    {
      Complex res;
      res.real=real+obj.real;
      res.imag=imag+obj.imag;
      return res;
    }
};
int main()
{
    cout<<"16115068 Sadanand Vishwas\n\n";
    Complex c1(2,3),c2(5,4);
    Complex c3;
    c3=c1+c2;
    c1.display();
    c2.display();
    c3.display();
    return 0;
}
