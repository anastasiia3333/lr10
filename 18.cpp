#include <iostream>
#include <fstream>
#include <cctype>
using namespace std;

int main() {
    ifstream inputFile("source.txt");
    ofstream outputFile("destination.txt");

    if (!inputFile || !outputFile) {
        cerr << "Error!!" << endl;
        return 1;
    }

    char ch;
    while (inputFile.get(ch)) {
        if (isalpha(ch)) {
            if (islower(ch)) {
                ch = toupper(ch); 
            } else {
                ch = tolower(ch); 
            }
        }
        outputFile << ch;
    }

    cout << "File copied successfully!" << endl;
    inputFile.close();
    outputFile.close();

    return 0;
}
