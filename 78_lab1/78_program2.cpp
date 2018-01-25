/*

 #include <std/disclaimer.h>

 This program takes two strings as input from the user and prints largest common subsequence
 as the output along with its length

 *The code is written in C++

 *Author: 16115078 - Siddharth Chandra, CSE, IV Semester


*/

//Inclusion of header file

#include <iostream>

using namespace std;

//Function prototype declaration

void largest_common_subsequence(string, string, unsigned long, unsigned long);

//Declaration of main() driver function

int main()
{
    string s1, s2;
    unsigned long a, b;
    cout << "Enter first string: ";
    cin >> s1;
    cout << endl << "Enter second string: ";
    cin >> s2;
    a = s1.size();
    b = s2.size();
    largest_common_subsequence(s1, s2, a, b);
    return 0;
}

//Declaration of function to evaluate lcs

void largest_common_subsequence(string s1, string s2, unsigned long a, unsigned long b)
{
    unsigned long *mat = new unsigned long[(a+1)*(b+1)];
    unsigned long i, j, end;
    for(i = 0; i <= a; i++)
    {
        for(j = 0; j <= b; j++)
        {
            if(i == 0 || j == 0)
            {
                mat[i*(b+1)+j] = 0;
            }

            else if(s1[i-1] == s2[j-1])
            {
                mat[i*(b+1)+j] = mat[(i-1)*(b+1)+(j-1)] + 1;
            }
            else
                mat[i*(b+1)+j] = max(mat[(i-1)*(b+1)+j], mat[i*(b+1)+(j-1)]);
        }
    }


    end = mat[a*(b+1)+b];


    char *text = new char[end+1];
    text[end] = '\0';

    i = a;
    j = b;

    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            text[--end] = s1[i-1];
            i--;
            j--;
        }
        else if (mat[(i-1)*(b+1)+j] > mat[i*(b+1)+(j-1)])
            i--;

        else
            j--;
    }


    cout << endl << "Largest common subsequence of the two strings is: " << text << endl << "Length is: " << mat[a*(b+1)+b];

}

//End of code



/*
 * Please insert your valuable comments and suggestions below

*/