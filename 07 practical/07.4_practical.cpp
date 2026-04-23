#include <iostream>
using namespace std;

class Shape {
public:
    virtual float Area() = 0;
};

class Rectangle : public Shape {
    float length, width;
public:
    Rectangle(float l, float w) {
        length = l;
        width = w;
    }
    float Area() {
        return length * width;
    }
};

class Circle : public Shape {
    float radius;
public:
    Circle(float r) {
        radius = r;
    }
    float Area() {
        return 3.14 * radius * radius;
    }
};

int main() {
    Shape* shapes1[2];
    shapes1[0] = new Rectangle(5, 3);
    shapes1[1] = new Circle(2);

    cout << "Static Storage Areas:\n";
    for (int i = 0; i < 2; i++) {
        cout << shapes1[i]->Area() << endl;
    }

    int n = 2;
    Shape** shapes2 = new Shape*[n];
    shapes2[0] = new Rectangle(4, 6);
    shapes2[1] = new Circle(3);

    cout << "Dynamic Storage Areas:\n";
    for (int i = 0; i < n; i++) {
        cout << shapes2[i]->Area() << endl;
    }

    for (int i = 0; i < 2; i++) delete shapes1[i];
    for (int i = 0; i < n; i++) delete shapes2[i];
    delete[] shapes2;

    return 0;
}
