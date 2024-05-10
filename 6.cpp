#include <iostream>
#include <string>
using namespace std;

struct skipchars
{
    string &str;
};

istream &operator>>(istream &stream, skipchars output)
{
    string temp;
    if (stream >> temp)
    {
        for (size_t i = 0; i < temp.size(); i += 10)
        {
            output.str += temp.substr(i, 5);
        }
    }
    return stream;
}

int main()
{
    string str;
    cout << "Enter line: ";
    cin >> skipchars{str};
    cout << "After using skipchar(): " << str;
    return 0;
}
