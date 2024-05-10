#include <iostream>
#include <iomanip>
using namespace std;

ostream &tab20(ostream &stream)
{
    return stream << '\t' << '\t' << '\t' << setw(20);
}

int main()
{
    cout << "Programming" << endl;
    cout << tab20 << "Programming" << endl;

    return 0;
}
