#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str, sub;

    cout << "Enter main string: ";
    cin >> str;

    cout << "Enter substring: ";
    cin >> sub;

    int count = 0;
    int pos = str.find(sub);

    while (pos != string::npos)
    {
        count++;
        pos = str.find(sub, pos + 1);
    }

    if (count > 0)
    {
        cout << "Substring found" << endl;
        cout << "Frequency: " << count;
    }
    else
    {
        cout << "Substring not found";
    }

    return 0;
}