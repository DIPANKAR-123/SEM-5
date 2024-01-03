#include <bits/stdc++.h>
using namespace std;
int checkPrecedence(char op)
{
    if (op == '|')
        return 1;
    else if (op == '^')
        return 2;
    else if (op == '&')
        return 3;
    else if (op == '+' || op == '-')
        return 4;
    else if (op == '*' || op == '/')
        return 5;
    else
        return -1;
}
int main()
{
    string expression, trimmedExpression;
    cout << "Enter the expression: ";
    cin >> expression;
    stack<vector<char>> st;
    bool error = false;
    vector<string> states;
    for (int i = 0; i < expression.size(); i++)
    {
        char x = expression[i];
        if (x == ' ')
        {
            continue;
        }

        trimmedExpression.push_back(x);
    }
    for (int i = 0; i < trimmedExpression.size(); i += 2)
    {
        char l = trimmedExpression[i];
        if (i == trimmedExpression.size() - 1)
        {
            while (st.size() > 0)
            {
                string x;
                if (l >= '0' && l <= '9')
                {
                    if (st.top()[1] >= '0' &&
                        st.top()[1] <= '9')
                        x = {'t', st.top()[1], st.top()[0], 't', l};
                    else
                        x = {st.top()[1], st.top()[0], 't', l};
                }
                else
                {
                    if (st.top()[1] >= '0' &&
                        st.top()[1] <= '9')
                        x = {'t', st.top()[1], st.top()[0], l};
                    else
                        x = {st.top()[1], st.top()[0], l};
                }
                l = '0' + states.size();
                states.push_back(x);
                st.pop();
            }
        }
        char op = trimmedExpression[i + 1];
        if (st.size() == 0)
        {
            st.push((vector<char>){op, l});
            continue;
        }

        int
            p1 = checkPrecedence(st.top()[0]),
            p2 = checkPrecedence(op);
        if (p1 == -1 || p2 == -1)
        {
            error = true;
            break;
        }
        while (p1 > p2 && st.size() > 0)
        {
            string x;
            if (l >= '0' && l <= '9')
            {
                if (st.top()[1] >= '0' && st.top()[1] <= '9')
                    x = {'t', st.top()[1], st.top()[0], 't', l};
                else
                    x = {st.top()[1], st.top()[0], 't', l};
            }
            else
            {
                if (st.top()[1] >= '0' && st.top()[1] <= '9')
                    x = {'t', st.top()[1], st.top()[0], l};
                else
                    x = {st.top()[1], st.top()[0], l};
            }
            l = '0' + states.size();
            states.push_back(x);
            st.pop();
            if (st.size() == 0)
                break;
            p1 = checkPrecedence(st.top()[0]);
            if (p1 == -1)
            {
                error = true;
                break;
            }
        }
        if (error == true)
            break;
        st.push((vector<char>){op, l});
    }
    if (error)
    {
        cout << "Error in arithmetic expression." << endl;
        return 0;
    }
    for (int i = 0; i < states.size(); i++)
    {
        string x = states[i];
        cout << "t" << i << " = " << x << endl;
    }
    cout << "out = t" << states.size() - 1 << endl;
    return 0;
}
