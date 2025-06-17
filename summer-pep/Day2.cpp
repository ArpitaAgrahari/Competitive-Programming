
// check wheatheer Ip address is valid or not

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool isValidIP(string s)
{
    int count = 0;
    stringstream ss(s);
    string part;
    while (getline(ss, part, '.'))
    {
        if (part.empty() || part.size() > 3)
            return false;
        for (char c : part)
        {
            if (!isdigit(c))
                return false;
        }
        int num = stoi(part);
        if (num < 0 || num > 255)
            return false;
        if (part[0] == '0' && part.size() > 1)
            return false;
        count++;
    }
    return count == 4;
}

int main()
{
    string s;
    cin >> s;
    if (isValidIP(s))
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}
