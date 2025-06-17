//  1. Check if a number is prime
// 🔹 Problem: Given an integer n, check whether it is a prime number.
// 🔹 Approach: A number is prime if it's only divisible by 1 and itself.
//             We only need to check divisibility up to sqrt(n).
// 🔹 Time: O(√n), Space: O(1)
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (isPrime(n))
        cout << "Prime\n";
    else
        cout << "Not Prime\n";
    return 0;
}

//  2. Check if two strings are anagrams
// 🔹 Problem: Given two strings, check if they are anagrams.
// 🔹 Approach: Sort both strings and compare them.
// 🔹 Time: O(n log n), Space: O(1)
bool isAnagram(string a, string b)
{
    if (a.length() != b.length())
        return false;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main_anagram()
{
    string s1, s2;
    cout << "Enter two strings: ";
    cin >> s1 >> s2;
    if (isAnagram(s1, s2))
        cout << "Anagram\n";
    else
        cout << "Not Anagram\n";
    return 0;
}

//  3. Check if a string is a palindrome
// 🔹 Problem: Given a string, check if it reads the same forward and backward.
// 🔹 Time: O(n), Space: O(1)
bool isPalindrome(string s)
{
    int l = 0, r = s.size() - 1;
    while (l < r)
    {
        if (s[l++] != s[r--])
            return false;
    }
    return true;
}

int main_palindrome()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    if (isPalindrome(s))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";
    return 0;
}

//  4. Check if string is pangram (contains all 26 letters)
// 🔹 Problem: Given a string, check if it contains all 26 letters.
// 🔹 Time: O(n), Space: O(1)
bool isPangram(string s)
{
    vector<bool> seen(26, false);
    for (char c : s)
    {
        if (isalpha(c))
            seen[tolower(c) - 'a'] = true;
    }
    return all_of(seen.begin(), seen.end(), [](bool b)
                  { return b; });
}

int main_pangram()
{
    string s;
    cin.ignore();
    cout << "Enter a sentence: ";
    getline(cin, s);
    if (isPangram(s))
        cout << "Pangram\n";
    else
        cout << "Not Pangram\n";
    return 0;
}

//  5. Print all subset sums of an array
// 🔹 Problem: Print all possible sums of subsets of a given array.
// 🔹 Time: O(2^n), Space: O(n)
void subsetSums(vector<int> &arr, int idx, int sum)
{
    if (idx == arr.size())
    {
        cout << sum << " ";
        return;
    }
    subsetSums(arr, idx + 1, sum);
    subsetSums(arr, idx + 1, sum + arr[idx]);
}

int main_subsetsum()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    cout << "Subset Sums: ";
    subsetSums(arr, 0, 0);
    return 0;
}

//  6. Length of string without using inbuilt function
// 🔹 Problem: Count characters in a string without using size()/length()
// 🔹 Time: O(n), Space: O(1)
int main_length()
{
    string s;
    cout << "Enter string: ";
    cin >> s;
    int count = 0;
    for (char c : s)
        count++;
    cout << "Length: " << count << endl;
    return 0;
}

//  7. Convert lowercase to uppercase and vice versa without inbuilt
// 🔹 Problem: Toggle the case of each character in a string.
// 🔹 Time: O(n), Space: O(1)
int main_togglecase()
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    for (char &c : str)
    {
        if (c >= 'a' && c <= 'z')
            c = c - 'a' + 'A';
        else if (c >= 'A' && c <= 'Z')
            c = c - 'A' + 'a';
    }
    cout << "Toggled: " << str << endl;
    return 0;
}

//  8. Count of each vowel in a string
// 🔹 Problem: Count how many times each vowel appears in the string.
// 🔹 Time: O(n), Space: O(1)
int main_vowelcount()
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    map<char, int> freq;
    for (char c : str)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            freq[c]++;
    }
    for (auto &p : freq)
        cout << p.first << ": " << p.second << endl;
    return 0;
}

//  9. Reverse each word in a sentence
// 🔹 Problem: Given a sentence, reverse every word individually.
// 🔹 Time: O(n), Space: O(n)
int main_reversewords()
{
    string str;
    cin.ignore();
    cout << "Enter sentence: ";
    getline(cin, str);
    stringstream ss(str);
    string word;
    while (ss >> word)
    {
        reverse(word.begin(), word.end());
        cout << word << " ";
    }
    cout << endl;
    return 0;
}