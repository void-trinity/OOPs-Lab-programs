/*
 #include<std/disclaimer.h>

*This program calculates the inverse of a matrix by using the adjoint method of finding the
 inverse

*The code is written in C++

*Author: 16115078 - Siddharth Chandra, CSE, IV Semester


 */

//Inclusion of header files

#include <iostream>
#include<cmath>
#include<iomanip>


using namespace std;

//Function prototype declaration

int _minor(int*, int, int, int);
int cofactor(int*, int, int, int);
int determinant(int*, int);
int* adjoint(int*, int);
float* inverse(int*, int, int);
float* identity(int*, float*, int);

//Declaration of main() driver function

int main()
{
    int n, i, j, det;
    cout << "Enter n for n x n matrix: ";
    cin >> n;

    int *mat = new int[n*n];
    int *adj = new int[n*n];
    float *inv = new float[n*n];
    float *iden = new float[n*n];

    cout << endl << "Enter elements of matrix n x n:" << endl;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cin >> mat[i*n+j];
        }
    }

    cout << endl << "The input matrix is:" << endl;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << mat[i*n+j] << "\t";
        }
        cout << endl;
    }

    det = determinant(mat, n);

    if(det == 0)
    {
        cout << endl << "Matrix is singular, cannot be inverted....";
    }

    else
    {
        cout << endl << det << endl;
        adj = adjoint(mat, n);
        inv = inverse(adj, n, det);
        iden = identity(mat, inv, n);
        cout << endl << "The inverse matrix is:" << endl;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cout << setw(5) << setprecision(2) << fixed << inv[i*n+j] << "\t";
            }
            cout << endl;
        }
        cout << endl << "Matrix multiplication:" << endl;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cout << round(iden[i*n+j]) << "\t";
            }
            cout << endl;
        }
    }
    return 0;
}

//Declaration of other functions. Name specifies the job they do

int determinant(int *mat, int n) {
    int i, det = 0;

    if (n == 1) {
        return mat[0];
    }

    for (i = 0; i < n; i++) {
        det += mat[i] * cofactor(mat, n, 0, i);
    }
    return det;
}

int cofactor(int *mat, int n, int x, int y)
{
    int sign = ((x+y)%2) == 0 ? 1 : -1;

    return (sign * _minor(mat, n, x, y));
}

int _minor(int *mat, int n, int x, int y)
{
    int *temp = new int[(n-1) * (n-1)];
    int i, j, a = 0, b = 0;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(i != x && j != y)
            {
                temp[a*(n-1)+b] = mat[i*n+j];
                b++;

                if(b == n-1)
                {
                    b = 0;
                    a++;
                }
            }
        }
    }

    return determinant(temp, n-1);
}

int* adjoint(int *mat, int n)
{
    int i, j;
    int *temp = new int[n*n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            temp[j*n+i] = cofactor(mat, n, i, j);
        }
    }

    cout << endl << "The adjoint matrix is:" << endl;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            cout << temp[i*n+j] << "\t";
        }
        cout << endl;
    }

    return temp;
}

float* inverse(int *mat, int n, int det)
{
    int i, j;
    float *temp = new float[n*n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            temp[i*n+j] = (float)mat[i*n+j]/det;
        }
    }

    cout << endl << "The inverse is:" << endl;
    return temp;
}

float* identity(int *mat, float *inv, int n)
{
    int i, j, k;
    float *temp = new float[n*n];
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            temp[i*n+j] = 0;
        }
    }
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            for(k = 0; k < n; k++)
            {
                temp[i*n+j] += mat[i*n+k] * inv[k*n+j];
            }
        }
    }
    return temp;
}


//End of code



/*
 * Please insert your valuable comments and suggestions below

*/