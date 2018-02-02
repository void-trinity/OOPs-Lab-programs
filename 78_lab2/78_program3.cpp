#include <iostream>
using namespace std;

class comp
{
    float real, img;
public:

    comp(float a = 0, float b = 0)
    {
        real = a;
        img = b;
    }

    comp add (comp B)
    {
        comp C;
        C.real = real + B.real;
        C.img = img + B.img;
        return C;
    }

    comp sub (comp B)
    {
        comp C;
        C.real = real - B.real;
        C.img = img - B.img;
        return C;
    }

    comp mul (comp B)
    {
        comp C;
        C.real = real * B.real - img * B.img;
        C.img = real * B.img + img * B.real;
        return C;
    }

    comp div (comp B)
    {
        comp C;
        C.real = (real * B.real + img * B.img) / (B.img * B.img + B.real * B.real);
        C.img = (-real * B.img + img * B.real) / (B.img * B.img + B.real * B.real);
        return C;
    }

    static comp add(comp A, comp B);

    void display()
    {
        cout << endl << real << " + i" << img;
    }

    void inp()
    {
        cout << endl << "Enter real and imaginary part separated via space: ";
        cin >> real >> img;
    }
};

comp comp::add(comp A, comp B)
{
    comp C;
    C.real = A.real + B.real;
    C.img = A.img + B.img;
    return C;
}

int main()
{
    comp A, B, C;
    int ch;
    A.inp();
    B.inp();
    do
    {
        cout << endl << endl << endl;
        cout << "_______________________" << endl;
        cout << "1: Add" << endl << "2: Subtract" << endl << "3: Multiply" << endl << "4: Divide"
             << endl << "5: Static Add" << endl << "6: Exit" << endl;
        cout << "_______________________" << endl;
        cin >> ch;
        switch(ch)
        {
            case 1: C = A.add(B);
                    C.display();
                break;
            case 2: C = A.sub(B);
                C.display();
                break;
            case 3: C = A.mul(B);
                C.display();
                break;
            case 4: C = A.div(B);
                C.display();
                break;
            case 5: C = comp::add(A,B);
                C.display();
                break;
            case 6:
                break;
            default: cout << endl << "Wrong Choice";
        }
    }while(ch!=6);
    return 0;
}
