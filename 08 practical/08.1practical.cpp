#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

int main() {
    int a, b;

    cout << "Enter numerator: ";
    if (!(cin >> a)) {
        throw invalid_argument("Invalid input: not an integer.");
    }

    cout << "Enter denominator: ";
    if (!(cin >> b)) {
        throw invalid_argument("Invalid input: not an integer.");
    }

    try {
        if (b == 0) throw runtime_error("Division by zero is not allowed.");
        cout << "Result: " << a / b << endl;
    }
    catch (const runtime_error& e) {
        cerr << "Runtime error: " << e.what() << endl;
    }
    catch (const invalid_argument& e) {
        cerr << "Invalid argument: " << e.what() << endl;
    }

    return 0;
}
