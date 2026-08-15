#include <iostream>
#include <string>
using namespace std;

class StringADT
{
    string str;

public:
    void input()
    {
        cin >> str;
    }

    void display()
    {
        cout << str;
    }

    int length()
    {
        return str.length();
    }

    bool isEmpty()
    {
        return str.empty();
    }
};

int main()
{
    StringADT s;

    s.input();

    cout << "String: ";
    s.display();

    cout << "\nLength: " << s.length();

    if (s.isEmpty())
        cout << "\nString is empty";
    else
        cout << "\nString is not empty";

    return 0;
}