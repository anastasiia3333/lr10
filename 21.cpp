#include <iostream>
#include <fstream>
using namespace std;

class Stack
{
    string fname;

public:
    Stack(const string &fname) : fname(fname) {}

    void push(char c)
    {
        ofstream file(fname, ios::app);
        if (!file.is_open())
        {
            cerr << "Error!!" << endl;
            return;
        }
        file.put(c);
        file.close();
    }

    char pop()
    {
        ifstream is(fname);
        string str;
        is >> str;
        is.close();

        ofstream os(fname);
        os << str.substr(0, str.size() - 1);
        os.close();

        return str.back();
    }

    bool isEmpty()
    {
        ifstream file(fname);
        file.seekg(0, ios::end);
        bool empty = file.tellg() == 0;
        file.close();
        return empty;
    }
};

int main()
{
    Stack stck("stack.txt");
    stck.push('Q');
    stck.push('W');
    stck.push('E');
    stck.push('R');
    stck.push('T');
    stck.push('Y');

    cout << "Popping from stack: ";
    while (!stck.isEmpty())
    {
        cout << stck.pop() << " ";
    }
    cout << endl;

    return 0;
}
