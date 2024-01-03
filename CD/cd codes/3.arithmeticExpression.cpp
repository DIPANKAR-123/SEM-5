#include <bits/stdc++.h>
using namespace std;
bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}
bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}
bool isBracketOpen(char ch)
{
    return (ch == '(' || ch == '[' || ch == '{');
}
char getCorrespondingChar(char ch)
{
    if (ch == ')')
    {
        return '(';
    }
    else if (ch == ']')
    {
        return '[';
    }
    return '{';
}
bool isValid(string str)
{
    int n = str.size();
    stack<int> st1;
    stack<char> st2;
    bool result = true;
    bool isTrue = true;
    for (int i = 0; i < n; i++)
    {
        char temp = str[i];
        if (isDigit(temp))
        {
            st1.push(temp - '0');
            if (isTrue)
            {
                isTrue = false;
            }
            else
                return false;
        }
        else if (isOperator(temp))
        {
            st2.push(temp);
            isTrue = true;
        }
        else
        {
            if (isBracketOpen(temp))
            {
                st2.push(temp);
            }
            else
            {
                bool flag = true;
                while (!st2.empty())
                {
                    char c = st2.top();
                    st2.pop();
                    if (c == getCorrespondingChar(temp))
                    {
                        flag = false;
                        break;
                    }
                    else
                    {
                        if (st1.size() < 2)
                        {
                            return false;
                        }
                        else
                        {
                            st1.pop();
                        }
                    }
                }
                if (flag)
                {
                    return false;
                }
            }
        }
    }
    while (!st2.empty())
    {
        char c = st2.top();
        st2.pop();
        if (!isOperator(c))
        {
            return false;
        }
        if (st1.size() < 2)
        {
            return false;
        }
        else
        {
            st1.pop();
        }
    }
    if (st1.size() > 1 || !st2.empty())
    {
        return false;
    }
    return result;
}
int main()
{
    string str;
    cout << "Enter a arithematic expression: ";
    cin >> str;
    if (isValid(str))
    {
        cout << "Valid Expression\n";
    }
    else
        cout << "Not a valid expression\n";
    return 0;
}
