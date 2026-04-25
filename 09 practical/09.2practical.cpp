#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

int main() {
    string sentence, word;
    map<string, int> frequency;

    cout << "Enter a sentence: ";
    getline(cin, sentence);

    istringstream ss(sentence);

    while (ss >> word) {
        for (int i = 0; i < word.length(); i++) {
            word[i] = tolower(word[i]);
        }
        frequency[word]++;
    }

    cout << "\nWord Frequencies:" << endl;
    for (map<string, int>::iterator it = frequency.begin(); it != frequency.end(); ++it) {
        cout << it->first << " : " << it->second << endl;
    }

    return 0;
}
