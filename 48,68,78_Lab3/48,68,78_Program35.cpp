#include<iostream>
using namespace std;

class Date
{
int day,month,year;
public:
    Date(int d=0,int m=0,int y=0){
    day=d;month=m;year=y;

    }
    void print()
    {
    cout<<"date is :"<<day<<"-"<<month<<"-"<<year<<endl;

    }
    bool isLeap(int y)
{
    if (y%100 != 0 && y%4 == 0 || y %400 == 0)
        return true;

    return false;
}

Date addDays(int days)
{ Date d;
cout<<days<<" days added.\nNew ";
    int offset = day;

    switch (month- 1)
    {
    case 11:
        offset += 30;
    case 10:
        offset += 31;
    case 9:
        offset += 30;
    case 8:
        offset += 31;
    case 7:
        offset += 31;
    case 6:
        offset += 30;
    case 5:
        offset += 31;
    case 4:
        offset += 30;
    case 3:
        offset += 31;
    case 2:
        offset += 28;
    case 1:
        offset += 31;
    }
    if (isLeap(year) && month > 2)
        offset += 1;
    int remDays = isLeap(year)?(366-offset):(365-offset);
    int y2, offset2;

    if (days<= remDays)
    {
        y2 = year;
        offset2=offset+days;
    }

    else
    {
        days -= remDays;
        y2 = year + 1;
        int y2days = isLeap(y2)?366:365;
        while (days > y2days)
        {
            days -= y2days;
            y2++;
            y2days = isLeap(y2)?366:365;
        }
        offset2 =days;
    }
    int months[13] = { 0, 31, 28, 31, 30, 31, 30,
                      31, 31, 30, 31, 30, 31 };

    if (isLeap(y2))
        months[2] = 29;
     int i;

    for (i = 1; i <= 12; i++)
    {
        if (offset2 <= months[i])
            break;
        offset2 = offset2 - months[i];
    }

    d.day = offset2;
    d.month = i;
    d.year=y2;
return d;
}

};

int main()
{
    cout<<"16115068 Sadanand Vishwas\n\n";

    Date d1(23,4,2015),d2;
    cout<<"Old ";
    d1.print();
    d2=d1.addDays(253+365);
    d2.print();

    return 0;

}
