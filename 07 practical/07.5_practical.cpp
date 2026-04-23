#include <iostream>
using namespace std;

class Grading {
protected:
    float marks;

public:
    Grading(float m) {
        marks = m;
    }

    virtual char computeGrade() = 0;
};

class Undergraduate : public Grading {
public:
    Undergraduate(float m) : Grading(m) {}

    char computeGrade() {
        if (marks >= 75) return 'A';
        else if (marks >= 60) return 'B';
        else if (marks >= 50) return 'C';
        else return 'F';
    }
};

class Postgraduate : public Grading {
public:
    Postgraduate(float m) : Grading(m) {}

    char computeGrade() {
        if (marks >= 85) return 'A';
        else if (marks >= 70) return 'B';
        else if (marks >= 60) return 'C';
        else return 'F';
    }
};

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Grading** students = new Grading*[n];

    for (int i = 0; i < n; i++) {
        int type;
        float marks;

        cout << "\n1. Undergraduate  2. Postgraduate\n";
        cout << "Enter type: ";
        cin >> type;

        cout << "Enter marks: ";
        cin >> marks;

        if (type == 1)
            students[i] = new Undergraduate(marks);
        else
            students[i] = new Postgraduate(marks);
    }

    cout << "\nGrades:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": " << students[i]->computeGrade() << endl;
    }

    for (int i = 0; i < n; i++) {
        delete students[i];
    }
    delete[] students;

    return 0;
}
