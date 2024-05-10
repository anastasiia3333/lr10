#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // double result = 10.0 / 3.0;
    // cout.precision(4);
    // cout.setf(ios::fixed);
    // cout << "Ios member function: " << result << endl;

    double result = 10.0 / 3.0;
    cout << "Manipulators: " << fixed << setprecision(4) << result << endl;

    return 0;
}
