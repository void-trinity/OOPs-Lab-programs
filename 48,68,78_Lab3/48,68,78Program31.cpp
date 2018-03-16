//Sadanand Vishwas 16115068
#include<iostream>
using namespace std;
#define size 50
class arry
{
    int arr[size];
    int n;
    public:
    void input(){
    cout<<"Enter size of array :";
    cin>>n;
    cout<<"Enter elements of array :\n";
    for(int i=0;i<n;i++){
    cin>>arr[i];
    }
    }
    void sorting(){
    int i,j,tmp;
    for(i=0;i<n;i++){

    for(j=i+1;j<n;j++){
    if(arr[i]>arr[j])
    {tmp=arr[i];
    arr[i]=arr[j];
    arr[j]=tmp;
    }
    }

}
    }
void print(){
cout<<"Sorted array is:\n";
for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<"\n";
}
};
int main(){
arry A;
A.input();
A.sorting();
A.print();
return 0;
}
