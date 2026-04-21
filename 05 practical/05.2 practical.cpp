#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream fin;
    string filename;
    cout<<"enter file name : ";
    cin >> filename;

    fin.open(filename);

    if(!fin)
    {
        cout << "Error: File cannot be opened!" << endl;
        return 0;
    }

    string line;
    int charCount = 0;
    int wordCount = 0;
    int lineCount = 0;

    while(getline(fin, line))
    {
        lineCount++;

        for(int i = 0; line[i] != '\0'; i++)
        {
            charCount++;

            if(line[i] != ' ' && line[i] != '\t' &&
               (i == 0 || line[i-1] == ' ' || line[i-1] == '\t'))
            {
                wordCount++;
            }
        }
    }

    fin.close();

    cout << "Total Lines: " << lineCount << endl;
    cout << "Total Words: " << wordCount << endl;
    cout << "Total Characters: " << charCount << endl;

    return 0;
}
