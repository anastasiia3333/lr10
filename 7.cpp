#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream source_file("source.txt");
    ofstream destination_file("destination.txt");

    if (!source_file || !destination_file)
    {
        cerr << "Error." << endl;
        return 1;
    }

    char ch;
    int count = 0;
    while (source_file >> noskipws >> ch)
    {
        destination_file << ch;
        count++;
    }
    cout << "Quantity of copied characters: " << count << endl;
    source_file.close();
    destination_file.close();
    return 0;
}
