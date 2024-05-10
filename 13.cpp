#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream infile("text13.txt");
    if (!infile)
    {
        cerr << "Error!!" << endl;
        return 1;
    }
    string line;
    int line_number = 1;
    while (getline(infile, line))
    {
        cout << "Line " << line_number << ": " << line << endl;
        line_number++;
    }
    infile.close();

    return 0;
}
