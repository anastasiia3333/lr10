#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() 
{
    ifstream inputFile("source.txt");
    if (!inputFile) 
    {
        cerr << "Error!!" << endl;
        return 1;
    }
    vector<string> lines;
    string line;
    while (getline(inputFile, line)) 
    {
        lines.push_back(line);
    }

    for (int i = lines.size() - 1; i >= 0; --i) {
        cout << lines[i] << endl;
    }
    inputFile.close();

    return 0;
}
