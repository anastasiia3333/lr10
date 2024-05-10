#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
#define SIZE 40

class inventory 
{
    char item[SIZE];
    int onhand;
    double cost;
public:
    inventory(const char *i, int o, double c) {
        strcpy(item, i);
        onhand = o;
        cost = c;
    }
    void store(fstream& stream) {
        stream << item << endl;
        stream << onhand << endl;
        stream << cost << endl;
    }
    void retrieve(fstream& stream) {
        stream.getline(item, SIZE); 
        stream >> onhand;
        stream.ignore();
        stream >> cost;
        stream.ignore();
    };
    friend ostream &operator <<(ostream &stream, inventory obj);
    friend istream &operator >>(istream &stream, inventory &obj);
};

ostream &operator <<(ostream &stream, inventory obj) 
{
    stream << obj.item << ": " << obj.onhand;
    stream << " on hand at $" << obj.cost << '\n';
    return stream;
}
istream &operator >>(istream &stream, inventory &obj) 
{
    cout << "Enter item name: ";
    stream >> obj.item;
    cout << "Enter number on hand: ";
    stream >> obj.onhand;
    cout << "Enter cost: ";
    stream >> obj.cost;
    return stream;
}

int main() 
{
    const int sz = 3;
    inventory array[sz] = {
        inventory("spoon", 5, 20.1), 
        inventory("plate", 14, 18.3),
        inventory("item3", 0, 0),
    };
    cin >> array[2];
    int num;
    fstream file("inventory.txt", ios::binary | ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return 1;
    }
    for (int i = 0; i < sz; ++i) {
        array[i].store(file);
    }
    file.close();
    file.open("inventory.txt", ios::binary | ios::in);
    if (!file.is_open()) {
        cout << "Cannot open file.\n";
        return 1;
    }
    int i = 0;
    while (i < sz && file) {
        array[i].retrieve(file);
        i++;
    }
    file.close();
    cout << "Enter the number of item (from 0 to " << i - 1 << "): ";
    cin >> num;
    if (num >= 0 && num < i) {
        cout << array[num] << endl;
    } else {
        cout << "Incorrect number." << endl;
    }
    return 0;
}
