#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<string> a;
    string s;
    cout << "Enter the lines:\n";
    while (true)
    {
        getline(cin, s);
        if (s == "")
            break;
        a.push_back(s);
    }
    int numberOfLines = a.size(), numberOfWhiteSpaces = 0;
    for (auto x : a)
    {
        for (auto y : x)
        {
            if (y == ' ')
                numberOfWhiteSpaces++;
        }
    }
    cout << "Number of white spaces:  "<<numberOfWhiteSpaces<<endl;
        cout<< "Number of lines: " << numberOfLines << endl;
    return 0;
}