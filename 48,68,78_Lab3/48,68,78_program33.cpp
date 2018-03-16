//Sadanand Vishwas 16115068
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
#define pi 3.14
class CArea
{
float area = 0;
char shape[10];
 public:
 CArea(){
     area=0;
}
 CArea(int r){
     if(r>0){
     area=pi*r*r;
     strcpy(shape,"circle");
     }
     
 }
 CArea(int h,int w){
     if(h>0 && w>0){
     area=h*w;
      strcpy(shape,"rectangle");
     }
 }
 CArea(int a,int b,int c){
     if(a+b > c && b+c > a && c+a > b)
     {
        float s;
        s=(a+b+c)/2.0;
        area=sqrt(s*(s-a)*(s-b)*(s-c));
          strcpy(shape,"triangle");
     }
 }
 void show(){
     cout << endl;
     if(area==0)
     cout<<"Invalid parameters\n";
     else
     cout<<"Area of "<<shape<<" is:"<<area<<"\n";
     
 }
};
int main(){
CArea circle(5), rectangle(4, 5), triangle(1, 3, 3);
circle.show();
rectangle.show();
triangle.show();

return 0;
}
