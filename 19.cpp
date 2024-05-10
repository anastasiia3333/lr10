#include <iostream>
#include <fstream>
#include <map>
#include <cctype>
using namespace std;

int main() 
{
    ifstream inputFile("source.txt");

    if (!inputFile) {
        cerr << "Error!!" << endl;
        return 1;
    }
    map<char, int> letterCount;
    char ch;
    while (inputFile.get(ch)) {
        if (isalpha(ch)) {
            ch = tolower(ch); 
            letterCount[ch]++;
        }
    }

    inputFile.close();
    cout << "Letter counts:" << endl;
    for (char letter = 'a'; letter <= 'z'; ++letter) {
        cout << letter << ": " << letterCount[letter] << endl;
    }

    return 0;
}
