#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream file("swap.txt");
    if (!file)
    {
        cout << "Error!!" << endl;
        return 1;
    }

    char c1, c2;
    while (file.get(c1) && file.get(c2))
    {
        file.seekp(-2, ios::cur);
        file << c2 << c1;
    }
    cout << "Swapped successfully";
    file.close();

    return 0;
}
