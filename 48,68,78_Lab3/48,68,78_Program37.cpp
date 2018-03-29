#include<iostream>
using  namespace std;
#define mx 100
class Array
{
int n;
int A[100];
public:
    void input(){
    cout<<"Enter size of array :";
    cin>>n;
    cout<<"Enter elements of array :\n";
    for(int i=0;i<n;i++){
    cin>>A[i];
    }
    }
    void print(){
    for(int i=0;i<n;i++)
        cout<<" "<<A[i];
    cout<<endl;

    }
    Array merg(Array &obj)
    { Array res;
    res.n=n+obj.n;
         int i = 0, j = 0, k = 0;
    while (i < n) {
        res.A[k] = A[i];
        i += 1;
        k += 1;
    }
    while (j < obj.n) {
        res.A[k] = obj.A[j];
        j += 1;
        k += 1;
    }
    return res;
    }
    void sortA(){
    int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (A[j] > A[j+1])
        {
           swap(A[j],A[j+1]);
           swapped = true;
        }
     }
     if (swapped == false)
        break;
   }
    }
};
int main()
{
cout<<"16115068 Sadanand Vishwas\n\n";
Array a1,a2,a3;
a1.input();
a2.input();
a3=a1.merg(a2);
a3.sortA();
cout<<"\nSorted array is:\n";
a3.print();
return 0;
}
