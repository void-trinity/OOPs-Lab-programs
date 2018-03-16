#include<iostream>
#include<cstring>
using namespace std;

class strng
{
    char str[100];
public:
    void input()
    {
        cout << "Enter string: ";
        fgets(str, 100, stdin);
    }

    void searchvowel()
    {
        for(int i = 0; i < strlen(str); i++)
        {
            if(str[i] == 'a ' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
               str[i] == 'A ' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                cout << endl << "Found " << str[i] << " at location " << i+1;
            }
        }
    }
};


int main()
{
    strng str;
    str.input();
    str.searchvowel();
}
