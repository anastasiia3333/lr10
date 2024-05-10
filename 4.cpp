#include <iostream>
#include <iomanip>
#include <chrono>
#include <ctime>
using namespace std;

ostream &tdm(ostream &os)
{
    auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());
    return os << put_time(localtime(&now), "%c");
}

int main()
{
    cout << "Current time and date: " << tdm << endl;

    return 0;
}
