// Matrix Multiplication using Class

#include <iostream>
using namespace std;

#define size 10

class Matrix
{
    int mat[size][size];
    public :
        int r,c;
        void getrc()
        {
            cout<<"Enter Row and Col of Matrix  : ";
            cin>>r>>c;
        }
        void getmat()
        {
            int i,j;
            cout<<"Enter Elements of Matrix :\n";
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    cin>>mat[i][j];
                }
            }
        }
        void show()
        {
            int i,j;
            cout<<"Product of Given Matrices :\n";
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                {
                    cout<<mat[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        Matrix mul(Matrix);
};

Matrix Matrix :: mul(Matrix B)
{
    Matrix C;
    int i,j,k,sum=0;
    C.r=r;
    C.c=B.c;
    for(i=0;i<r;i++)
    {
        for(j=0;j<B.c;j++)
        {
            sum=0;
            for(k=0;k<r;k++)
                sum=sum+mat[i][k]*B.mat[k][j];
            C.mat[i][j]=sum;
        }
    }
    return C;
}

int main()
{
    Matrix A,B,C;
    A.getrc();
    B.getrc();
    if(A.c!=B.r)
        cout<<"Multiplication Not Possible !!\n";
    else
    {
        A.getmat();
        B.getmat();
        C=A.mul(B);
        C.show();
    }
    return 0;
}
