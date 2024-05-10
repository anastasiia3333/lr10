#include <iostream>
#include <iomanip>
using namespace std;

ostream &sethex(ostream &os)
{
    os << hex << uppercase << showbase;
    return os;
}

ostream &reset(ostream &os)
{
    os << dec << nouppercase << noshowbase;
    return os;
}

int main()
{
    int num = 130;
    cout << "Number with hex format: " << sethex << num << endl;
    cout << reset;
    cout << "Number without hex format: " << num << endl;

    return 0;
}
