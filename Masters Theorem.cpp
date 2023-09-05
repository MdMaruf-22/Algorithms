#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int x;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '=')
        {
            x = i + 1;
            break;
        }
    }
    char a, b, k, p;
    if (s[x] != 'T')
        a = s[x];
    else
        a = '1';
    for (int i = x;; i++)
    {
        if (s[i] == 'n')
        {
            x = i;
            break;
        }
    }
    if (s[x + 1] == '/')
        b = s[x + 2];
    else
        b = '1';
    ++x;
    for (int i = x;; i++)
    {
        if (s[i] == '+' || s[i]=='-')
        {
            x = i;
            break;
        }
    }
    if (s[x + 1] == 'n')
    {
        if (s[x + 2] == '^')
        {
            k = s[x + 3];
            x += 3;
        }
        else
            k = '1';
    }
    else
        k = '0';
    x += 2;
    if (x >= s.size())
        p = '0';
    else
    {
        for (int i = x;; i++)
        {
            if (s[i] == 'n')
            {
                x = i;
                break;
            }
        }
        if (s[x + 1] == '^')
            p = s[x + 2];
        else
            p = '1';
    }
    int u = a - '0';
    int v = b - '0';
    int w = k - '0';
    int y = p - '0';
    cout << u << " " << v << " " << w << " " << y << endl;
    if (u < 1 || b <= 1)
    {
        cout << "Invalid" << endl;
        return 0;
    }
    int lg = log2(u) / log2(v);
    cout << lg << endl;
    if (lg > w)
    {
        cout << "n^" << lg << endl;
    }
    else if (lg < w)
    {
        if (p >= 0)
        {
            cout << "n^" << k << "*logn^" << y << endl;
        }
        else
            cout << "n^" << k << endl;
    }
    else
    {
        if (p > -1)
        {
            cout << "n^" << k << "*logn^" << y + 1 << endl;
        }
        else if (p == -1)
        {
            cout << "n^" << k << "*loglogn" << endl;
        }
        else
        {
            cout << "n^" << k << endl;
        }
    }
}