#include<iostream>
#include<iomanip>
using namespace std;

ostream& currency(ostream& os)
{
    os << "Rs. ";
    return os;
}
class Student
{
    string name;
    int marks;
    double fees;
public:
    void input(string n, int m, double f)
    {
        name = n;
        marks = m;
        fees = f;
    }
    void display()
    {
        cout << left << setw(15) << name
             << setw(10) << marks
             << fixed << setprecision(2) << currency << fees
             << endl;
    }
};

int main()
{
    Student s1, s2, s3;

    s1.input("harry", 85, 25000.5);
    s2.input("hermione", 92, 30000.75);
    s3.input("Ron", 78, 42000);

    cout << left << setw(15) << "Name"<< setw(10) << "Marks"<< "Fees" << endl;
    cout << setfill('-') << setw(32) << "" << setfill(' ') << endl;

    s1.display();
    s2.display();
    s3.display();

    return 0;
}
