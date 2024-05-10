#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

class account 
{
    int customer;
    char name[80];
    double balance;

public:
    account(int c, char *n, double b) 
    {
        customer = c;
        strcpy(name, n);
        balance = b;
    }

    friend ostream& operator<<(ostream& os, const account& acc);
};

ostream& operator<<(ostream& os, const account& acc) 
{
    os << "Customer code: " << acc.customer << endl;
    os << "Name: " << acc.name << endl;
    os << "Balance: " << acc.balance << endl;
    return os;
}

int main() {
    ofstream outFile("customer.txt");
    if (!outFile) 
    {
        cerr << "Error!!" << endl;
        return 1;
    } 

    int customerID;
    char name[80];
    double balance;

    cout << "Enter customer ID: ";
    cin >> customerID;
    cin.ignore(); 
    cout << "Enter customer name: ";
    cin.get(name, 80);
    cin.ignore(80, '\n'); 
    cout << "Enter balance: ";
    cin >> balance;
    account customer(customerID, name, balance);
    outFile << customer;
    outFile.close();
    cout << "Data was successfully written!" << endl;

    return 0;
}
