#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void saveToFile(const string& filename, const string& content) {
    ofstream outFile(filename,ios::out);
    if (outFile.is_open()) {
        outFile << content;
        outFile.close();
        cout << "File saved successfully!\n";
    }
    else {
        cout << "Failed to open file for saving.\n";
    }
}

string loadFromFile(const string& filename) {
    ifstream inFile(filename,ios::in);
    string content, line;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            content += line + "\n";
        }
        inFile.close();
    }
    else {
        cout << "Failed to open file for reading.\n";
    }
    return content;
}


void textEditor() {
    string content, filename;
    char option;

    cout << "Welcome to Simple Text Editor!\n";
    cout << "Enter filename: ";
    cin >> filename;
    cin.ignore();


    while (true) {
        system("cls");
    cout << "1. Add Text\n2. Read from file\n3. Exit\nChoose an option: ";
    cin >> option;
    cin.ignore();
    string newText;
        switch (option) {
        case('1'):
           
    cout << "Enter text (type \"SAVE\" on a new line to stop):\n";
    while (true) {
        getline(cin, newText);
        if (newText == "SAVE") 
        {
            saveToFile(filename, content);
                break;
        }
                content += newText + "\n";
            }
            break;
        case('2'):
            content = loadFromFile(filename);
            cout << "Loaded content:\n" << content;
            break;


        case('3'):
            exit(1);
            break;
        }
        system("pause");
    
    }
}

int main() {
    textEditor();
    return 0;
}
