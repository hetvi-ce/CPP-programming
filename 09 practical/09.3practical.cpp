#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    set<int> uniqueNumbers;
    vector<int> result;
    int n, val;

    cout << "Enter number of integers: ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        uniqueNumbers.insert(val);
    }

    cout << "\nUnique sorted elements using set iterator: ";
    for (set<int>::iterator it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ++it) {
        cout << *it << " ";
    }

    for (set<int>::iterator it = uniqueNumbers.begin(); it != uniqueNumbers.end(); ++it) {
        result.push_back(*it);
    }

    cout << "\nElements stored in vector: ";
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
        cout << *it << " ";
    }

    cout << endl;
    return 0;
}
