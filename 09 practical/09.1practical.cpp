#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> numbers;
    int n, val;

    cout << "Enter number of integers: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        numbers.push_back(val);
    }

    cout << "\nOriginal vector: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    reverse(numbers.begin(), numbers.end());

    cout << "\nAfter std::reverse(): ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    vector<int>::iterator front = numbers.begin();
    vector<int>::iterator back = numbers.end() - 1;

    while (front < back) {
        swap(*front, *back);
        ++front;
        --back;
    }

    cout << "\nAfter manual iterator reversal: ";
    for (vector<int>::iterator it = numbers.begin(); it != numbers.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
