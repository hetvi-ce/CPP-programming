#include<iostream>
using namespace std;

class complex
{
    int real;
    int img;

public:
    complex(int re = 0, int im = 0)
    {
        real = re;
        img = im;
    }

    void input()
    {
        cin >> real >> img;
    }

    complex operator+(complex c);
    complex operator-(complex c);

    void display();
};

complex complex::operator+(complex c)
{
    complex temp;
    temp.real = real + c.real;
    temp.img = img + c.img;
    return temp;
}

complex complex::operator-(complex c)
{
    complex temp;
    temp.real = real - c.real;
    temp.img = img - c.img;
    return temp;
}

void complex::display()
{
    if(img >= 0)
        cout << real << " + " << img << "i";
    else
        cout << real << " - " << -img << "i";
}

int main()
{
    complex c1, c2, c3, c4;

    cout << "Enter first complex number (real imag): ";
    c1.input();

    cout << "Enter second complex number (real imag): ";
    c2.input();

    c3 = c1 + c2;
    c4 = c1 - c2;

    cout << endl << "First Complex Number: ";
    c1.display();

    cout << endl << "Second Complex Number: ";
    c2.display();

    cout << endl << endl << "Addition Result: ";
    c3.display();

    cout << endl << "Subtraction Result: ";
    c4.display();

    return 0;
}
