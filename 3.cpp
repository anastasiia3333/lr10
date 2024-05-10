#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

class Date {
public:
    char d[9];
    void setDate(const char* date);
    friend istream& operator>>(istream& is, Date& dt);
    friend ostream& operator<<(ostream& os, const Date& dt);
};

void Date::setDate(const char* date) {
    if (strlen(date) == 8) {
        strcpy(d, date);
    } else {
        cout << "Incorrect format." << endl;
        strcpy(d, "00000000");
    }
    d[8] = '\0';
}

istream& operator>>(istream& is, Date& dt) {
    char input[9];
    cout << "Enter date in ddmmyyyy format: ";
    is >> setw(9) >> input;
    dt.setDate(input);
    return is;
}

ostream& operator<<(ostream& os, const Date& dt) {
    os << "Date: ";
    for (int i = 0; i < 8; i++) {
        os << dt.d[i];
        if (i == 1 || i == 3) os << '/';
    }
    return os;
}

int main() {
    Date myDate;
    cin >> myDate;
    cout << myDate << endl;
    return 0;
}
