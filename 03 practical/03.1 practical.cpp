#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    double basicSalary;
    double bonus;

public:
    Employee(string n = "", double bSalary = 0.0, double bns = 1000.0) {
        name = n;
        basicSalary = bSalary;
        bonus = bns;
    }

    inline double calculateTotalSalary() const {
        return basicSalary + bonus;
    }

    void setDetails(string n, double bSalary, double bns = 1000.0) {
        name = n;
        basicSalary = bSalary;
        bonus = bns;
    }

    void display() const {
        cout << "\nEmployee Name: " << name << endl;
        cout << "Basic Salary: " << basicSalary << endl;
        cout << "Bonus: " << bonus << endl;
        cout << "Total Salary: " << calculateTotalSalary() << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    int n;

    cout << "Enter number of employees: ";
    cin >> n;

    Employee* employees = new Employee[n];

    for (int i = 0; i < n; i++) {
        string name;
        double basicSalary, bonus;
        char choice;

        cout << "\nEnter details for Employee " << i + 1 << endl;

        cout << "Name: ";
        cin >> name;

        cout << "Basic Salary: ";
        cin >> basicSalary;

        cout << "Do you want to enter custom bonus? (y/n): ";
        cin >> choice;

        if (choice == 'y' || choice == 'Y') {
            cout << "Enter Bonus: ";
            cin >> bonus;
            employees[i].setDetails(name, basicSalary, bonus);
        } else {
            employees[i].setDetails(name, basicSalary);
        }
    }

    cout << "\n===== Employee Payroll Details =====\n";

    for (int i = 0; i < n; i++) {
        employees[i].display();
    }

    delete[] employees;

    return 0;
}
