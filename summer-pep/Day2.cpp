
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

// encrypiton and decryption in CPP

#include <iostream>
using namespace std;

string encrypt(string s, string key)
{
    string output = s;
    for (int i = 0; i < s.size(); ++i)
    {
        output[i] = s[i] ^ key[i - key.size()];
    }
    return output;
}
int main()
{
    string s;
    cin >> s;
    string key = "abcdefghijklmn";
    string en = encrypt(s, key);
    cout << en << endl;
    string de = encrypt(en, key);
    cout << de << endl;
}

// to make a sentence a palidrome leeter to claculate ; convert innot palidrome
// ex malayal   o/p malayalam and cnt 2 adding am

#include <iostream>
using namespace std;

bool check(string str)
{
    int l = 0, h = str.length() - 1;
    while (l <= h)
    {
        if (str[l++] != str[h--])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    cin >> str;
    string res = "";
    for (int i = 0; i < str.length(); i++)
    {
        res = str.substr(0, i + 1);
        string temp = str + string(res.rbegin(), res.rend());
        if (check(temp))
        {
            cout << temp << endl;
            break;
        }
    }
}

// input 2 number find gcd
#include <bits/stdc++.h>
using namespace std;
int findgcd(int a, int b)
{
    if (b == 0)
        return a;
    return findgcd(b, a % b);
}
int main()
{
    int a, b;
    cin >> a >> b;
    int res = findgcd(a, b);
    cout << res << endl;
}

// using built in
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int a, b;
    cin >> a >> b;
    int res = __gcd(a, b);
    cout << res << endl;
}
