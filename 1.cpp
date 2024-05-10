#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    string s = "I hate C++!";
    int width = 30;
    int spaces = (width - s.length()) / 2;

    cout << setfill(':');
    cout << setw(spaces) << "" << s << setw(width - spaces - s.length()) << "" << endl;

    return 0;
}
