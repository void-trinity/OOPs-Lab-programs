#include<iostream>
#include<cstring>
using namespace std;

void searchvowel(char *, int);

int main()
{
    char str[100];
    cout << "Enter string: ";
    fgets(str, 100, stdin);
    searchvowel(str, strlen(str));
}

void searchvowel(char *s, int n)
{
    for(int i = 0; i < n; i++)
    {
        if(s[i] == 'a ' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' ||
           s[i] == 'A ' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U') {
            cout << endl << "Found " << s[i] << " at location " << i+1;
        }
    }
}
