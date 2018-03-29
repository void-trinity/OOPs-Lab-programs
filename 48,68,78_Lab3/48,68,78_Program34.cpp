#include<iostream>
using namespace std;

class Time
{
    int hour,mins,sec;
public:
    Time(){
    hour=0;mins=0;sec=0;}

    Time(int h,int m,int s){
    hour=h;mins=m;sec=s;}
    Time add(Time &obj){
    Time res;
    res.sec=(sec+obj.sec)%60;
    res.mins=(mins+obj.mins+(sec+obj.sec)/60)%60;
    res.hour=hour+obj.hour+(mins+obj.mins+(sec+obj.sec)/60)/60;
    return res;
    }
    void show(){

    cout<<hour<<" hours "<<mins<<" minutes "<<sec<<" seconds"<<endl;
    }

};
int main()
{ cout<<"16115068 Sadanand Vishwas\n\n";
Time t1(6,50,57),t2(3,30,40);
Time t3;
t3=t1.add(t2);
t1.show();
t2.show();
t3.show();

   return 0;
}
