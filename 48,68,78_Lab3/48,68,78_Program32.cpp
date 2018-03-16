//Sadanand Vishwas 16115068
#include<iostream>
using namespace std;

class pascalt
{
  int n;
  public:
  void input(){
      cout<<"Enter No. of Lines :";
      cin>>n;
  }
   int Coeff(int l,int k)
{
    int r = 1;
    if (k > l - k)
    k = l- k;
    for (int i = 0; i < k; ++i)
    {
        r *= (l- i);
        r /= (i + 1);
    }
     
    return r;
}
  void print()
{
    cout<<"Required Pascal's Triangle is:\n";
    for (int l = 0; l< n; l++)
    {
        for (int i = 0; i <= l; i++)
            
                   cout<<Coeff(l, i)<<" ";
        cout<<"\n";
    }
}
 
};
int main(){
pascalt P;
P.input();
P.print();
return 0;
}
