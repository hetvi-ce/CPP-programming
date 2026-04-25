#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
    map<string, vector<string>> directory;
    int choice;
    string folderName, fileName;

    do {
        cout << "\n--- Directory Management System ---" << endl;
        cout << "1. Add Folder" << endl;
        cout << "2. Add File to Folder" << endl;
        cout << "3. Display All Folders and Files" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter folder name: ";
                cin >> folderName;
                if (directory.find(folderName) == directory.end()) {
                    directory[folderName] = vector<string>();
                    cout << "Folder '" << folderName << "' created." << endl;
                } else {
                    cout << "Folder already exists." << endl;
                }
                break;

            case 2:
                cout << "Enter folder name: ";
                cin >> folderName;
                if (directory.find(folderName) != directory.end()) {
                    cout << "Enter file name: ";
                    cin >> fileName;
                    directory[folderName].push_back(fileName);
                    cout << "File '" << fileName << "' added to '" << folderName << "'." << endl;
                } else {
                    cout << "Folder not found." << endl;
                }
                break;

            case 3:
                if (directory.empty()) {
                    cout << "Directory is empty." << endl;
                } else {
                    cout << "\n--- Directory Contents (Sorted Alphabetically) ---" << endl;
                    for (map<string, vector<string>>::iterator it = directory.begin(); it != directory.end(); ++it) {
                        cout << "[" << it->first << "]" << endl;
                        if (it->second.empty()) {
                            cout << "  (no files)" << endl;
                        } else {
                            for (vector<string>::iterator fit = it->second.begin(); fit != it->second.end(); ++fit) {
                                cout << "  - " << *fit << endl;
                            }
                        }
                    }
                }
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}
