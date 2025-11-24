#include <bits/stdc++.h>
using namespace std;

bool isPal(string s, int i)
{
    int j = s.size() - i - 1;
    if (i >= j)
        return true;
    if (s[i] != s[j])
        return false;
    return isPal(s, i + 1);
}

int main()
{
    string str, clean = "";
    getline(cin, str);

    for (char c : str)
        if (isalnum(c))
            clean += tolower(c);

    if (isPal(clean, 0))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
}
