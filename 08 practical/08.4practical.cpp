#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

bool isValidNumber(const string& s) {
    if (s.empty()) return false;
    int start = 0;
    if (s[0] == '-') start = 1;
    for (int i = start; i < s.length(); i++) {
        if (!isdigit(s[i]) && s[i] != '.') return false;
    }
    return true;
}

void processFile(ifstream& file) {
    string line;
    int lineNumber = 0;
    int validLines = 0;
    int invalidLines = 0;
    double total = 0.0;

    while (getline(file, line)) {
        lineNumber++;
        istringstream ss(line);
        string token;
        double lineSum = 0.0;
        bool lineValid = true;
        int count = 0;

        while (ss >> token) {
            if (!isValidNumber(token)) {
                cerr << "Corrupted data on line " << lineNumber << ": '" << token << "' is not a valid number. Skipping line." << endl;
                lineValid = false;
                break;
            }
            lineSum += stod(token);
            count++;
        }

        if (lineValid && count > 0) {
            double avg = lineSum / count;
            cout << "Line " << lineNumber << " -> Sum: " << lineSum << ", Average: " << avg << endl;
            total += lineSum;
            validLines++;
        } else if (lineValid && count == 0) {
            cerr << "Line " << lineNumber << " is empty. Skipping." << endl;
            invalidLines++;
        } else {
            invalidLines++;
        }
    }

    cout << "\n--- Summary ---" << endl;
    cout << "Total valid lines processed : " << validLines << endl;
    cout << "Total invalid lines skipped : " << invalidLines << endl;
    cout << "Grand total of all values   : " << total << endl;
}

int main() {
    string filePath;
    ifstream file;

    while (true) {
        cout << "Enter file path (or 'exit' to quit): ";
        cin >> filePath;

        if (filePath == "exit") {
            cout << "Exiting program." << endl;
            return 0;
        }

        file.open(filePath);

        if (!file.is_open()) {
            cerr << "Error: File '" << filePath << "' could not be opened. Please try again." << endl;
        } else {
            break;
        }
    }

    try {
        processFile(file);
    }
    catch (const exception& e) {
        cerr << "Unexpected error during file processing: " << e.what() << endl;
    }

    file.close();
    return 0;
}
