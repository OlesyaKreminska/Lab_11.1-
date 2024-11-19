#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void CreateTXT(const char* fname) {
    ofstream fout(fname);
    if (!fout) {
        cerr << "Error opening file for writing!" << endl;
        return;
    }
    char ch;
    string line;
    do {
        cin.ignore(); 
        cout << "Enter line: ";
        getline(cin, line);
        fout << line << endl;
        cout << "Continue? (y/n): ";
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
    fout.close();
}

void PrintTXT(const char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }
    string line;
    while (getline(fin, line)) {
        cout << line << endl;
    }
    fin.close();
}

void FindPattern(const char* fname) {
    ifstream fin(fname);
    if (!fin) {
        cerr << "Error opening file for reading!" << endl;
        return;
    }

    string line;
    int lineNumber = 0; 
    bool found = false;

    while (getline(fin, line)) {
        lineNumber++;
        for (size_t j = 1; j < line.length() - 1; j++) { 
            if (line[j - 1] == 'n' && line[j + 1] == 'o') {
                cout << "Found at line " << lineNumber  << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No such pattern found in the file." << endl;
    }

    fin.close();
}

int main() {
    char fname[100];

    
    cout << "Enter file name: ";
    cin >> fname;

   
    CreateTXT(fname);

   
    cout << "\nFile content:\n";
    PrintTXT(fname);

    
    cout << "\nSearching for pattern...\n";
    FindPattern(fname);

    return 0;
}
