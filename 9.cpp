#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int countWordsInFile(const string& filename) 
{
    ifstream file(filename);
    string word;
    int wordCount = 0;
    if (file.is_open()) 
    {
        while (file >> word) 
        {
            wordCount++;
        }
        file.close();
    } else 
    {
        cout << "Error!! " << filename << endl;
        return -1;
    }

    return wordCount;
}

int main() 
{
    string filename = "file.txt";
    int wordCount = countWordsInFile(filename);
    if (wordCount != -1) {
        cout << "Quantity of words in file: " << wordCount << endl;
    }

    return 0;
}


