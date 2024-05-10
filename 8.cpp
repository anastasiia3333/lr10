#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() 
{
    ofstream outFile("phone.txt", ios::app);
    if (outFile.is_open()) 
    {
        string name, surname, phone;
        cout << "Enter name: ";
        getline(cin, name);

        cout << "Enter surname: ";
        getline(cin, surname);

        cout << "Enter phone number: ";
        getline(cin, phone);
        outFile << name << " " << surname << " " << phone << endl;

        cout << "Your info was successfuly put to the file!" << endl;
        outFile.close();
    } else 
    {
        cout << "Error!!" << endl;
    }

    return 0;
}
