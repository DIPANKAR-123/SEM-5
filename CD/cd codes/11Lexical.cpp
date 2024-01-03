#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the no. of lines: ";
    cin >> n;
    vector<string> vec;
    n++;
    while (n--)
    {
        string str;
        getline(cin, str);
        vec.push_back(str);
    }
    vector<string> keywords = {"int", "float", "double", "bool", "char", "if",
                               "else", "while", "for"};
    vector<string> operators = {"=", "+", "-", "*", "/", "==", "+=", "-=", "*=", "/=",
                                "!=", ">=", "<=", ">", "<", "&", "|", "^", "%"};
    vector<string> v1;
    vector<string> v2;
    vector<string> v3;
    set<string> v4;
    for (auto it : vec)
    {
        string str = it;
        string s1;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == ' ' || str[i] == ';' || str[i] == '(' || str[i] == ')' || str[i] == '{' || str[i] == '}' ||  str[i] == '[' || str[i] == ']' || str[i] == ',')
                continue;
            s1.push_back(str[i]);
            int fl = 0;
            for (auto it1 : keywords)
            {
                if (s1 == it1)
                {
                    fl = 1;
                    v1.push_back(s1);
                    s1.clear();
                    break;
                }
            }
            if (!fl)
            {
                for (auto it1 : operators)
                {
                    if (s1 == it1)
                    {
                        fl = 1;
                        break;
                    }
                }
                if (fl)
                {
                    if (str[i + 1] == '=')
                        continue;
                    else
                    {
                        v2.push_back(s1);
                        s1.clear();
                    }
                }
            }
            if (!fl)
            {
                int fl1 = 1;
                if ((str[i + 1] >= '0' && str[i + 1] <= '9') || str[i + 1] == '.')
                    continue;
                for (auto it1 : s1)
                {
                    if ((it1 >= '0' && it1 <= '9') || it1 == '.')
                        continue;
                    else
                    {
                        fl1 = 0;
                        break;
                    }
                }
                if (s1 == "true" || s1 == "false")
                    fl1 = 1;
                if (fl1)
                {
                    v3.push_back(s1);
                    s1.clear();
                    fl = 1;
                }
            }
            if (!fl)
            {
                if (str[i + 1] == ' ' || str[i + 1] == ',' || str[i + 1] == '=' || str[i + 1] == '+' ||
                    str[i + 1] == '-' || str[i + 1] == '*' || str[i + 1] == '/' || str[i + 1] == ')' || str[i + 1] == '|' || str[i + 1] == '!')
                {
                    v4.insert(s1);
                    s1.clear();
                    fl = 1;
                }
            }
        }
    }
    cout << "\nKeywords:- \n";
    for (auto it : v1)
    {
        cout << it << ", ";
    }
    cout << "\nTotal = " << v1.size() << "\n \n";
    cout << "Operators:- \n";
    for (auto it : v2)
    {
        cout << it << ", ";
    }
    cout << "\nTotal = " << v2.size() << "\n \n";
    cout << "Constants:- \n";
    for (auto it : v3)
    {
        cout << it << ", ";
    }
    cout << "\nTotal = " << v3.size() << "\n \n";
    cout << "Identifiers:- \n";
    for (auto it : v4)
    {
        cout << it << ", ";
    }
    cout << "\nTotal = " << v4.size() << "\n \n";
    return 0;
}
