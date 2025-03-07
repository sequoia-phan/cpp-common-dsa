#ifndef STRING_H
#define STRING_H

#include <iostream>
using namespace std;

void regular_str()
{
    char ch[] = "da";
    char s2[4] = {'g', 'f', 'g', '\0'};
    char ch4[5] = "ghdg";
    cout << ch << endl;
    cout << s2 << endl;
    cout << ch4 << endl;
}

void string_cpp()
{
    string meow(5, 'g');
    cout << meow << endl;

    string s;
    cout << "enter string: " << endl;
    cin >> s;
    cout << "string is: " << s << endl;
}

void pointer_str()
{
    string s = "nhat dep trai";
    char *p = &s[0];

    // while (*p != '\0')
    // {
    //     cout << *p;
    //     p++;
    // }
    cout << endl;
    cout << "alo: " << p << endl;
}

void str_function()
{
    // declaring an iterator
    string::iterator itr;

    // declaring a reverse iterator
    string::reverse_iterator rit;

    string s = "nhat dep trai";
    itr = s.begin();
    cout << "Pointing to the start of the string: " << *itr << endl;
    itr = s.end() - 1;
    cout << "pointing to the end of the string: " << *itr << endl;

    rit = s.rbegin();
    cout << "Pointing to the last character of the string: " << *rit << endl;

    rit = s.rend() - 1;
    cout << "Pointing to the first character of the string: " << *rit << endl;

    cout << "The length of the string is " << s.length() << endl;

    cout << "The capacity of string is " << s.capacity() << endl;

    s.resize(10);
    cout << "The string after using resize function is " << s << endl;

    s.resize(20);
    cout << "The capacity of string before using shrink_to_fit function is " << s.capacity() << endl;

    s.shrink_to_fit();
    cout << "The capacity of string after using shrink_to_fit function is " << s.capacity() << endl;
}

void str_reverse()
{
    string s = "nhat dep trai";
    reverse(s.begin(), s.end());
    cout << s;
}

void str_rev_iter()
{
    string s = "nhat dep trai";
    s = string(s.rbegin(), s.rend());
    cout << s;
}

void str_rev_stack()
{
    string s = "nhat dep trai";
    stack<char> st;

    for (char c : s)
        st.push(c);
    s.clear();

    while (!st.empty())
    {
        s.push_back(st.top());
        st.pop();
    }

    cout << s;
}

void str_rev_ptr()
{
    string s = "nhat dep trai";

    int l = 0;
    int r = s.length() - 1;

    while (l < r)
    {
        swap(s[l], s[r]);

        l++;

        r--;
    }

    cout << s;
}

void str_rev_recur(string &s, int l, int r)
{
    if (l >= r)
        return;
    swap(s[l], s[r]);

    str_rev_recur(s, l + 1, r - 1);
}

void exec_str_rev_recur()
{
    string s = "hello world";
    str_rev_recur(s, 0, s.length() - 1);
    cout << s;
}

void tokenize_strstream()
{
    string line = "Nhat dep trai phai thu moi biet duoc";
    vector<string> tokens;

    stringstream check1(line);

    string intermediate;
    while (getline(check1, intermediate, ' '))
    {
        tokens.push_back(intermediate);
    }

    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokens[i] << "\n";
    }
}

void tokenize_strtok()
{
    char str[] = "Nhat-dep-trai-phai";
    char *token = strtok(str, "-");

    while (token != NULL)
    {
        printf("%s\n", token);
        token = strtok(NULL, "-");
    }
}
#endif