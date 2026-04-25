#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

class NegativeNumberException : public exception {
public:
    const char* what() const noexcept override {
        return "Error: Cannot compute square root of a negative number.";
    }
};

int main() {
    double num;

    cout << "Enter a number: ";
    cin >> num;

    try {
        if (num < 0) throw NegativeNumberException();
        cout << "Square root: " << sqrt(num) << endl;
    }
    catch (const NegativeNumberException& e) {
        cerr << e.what() << endl;
    }

    return 0;
}
