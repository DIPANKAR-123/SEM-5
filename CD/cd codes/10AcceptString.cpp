#include <bits/stdc++.h>
using namespace std;
bool check = false;
void func(string &s, string &ans,
          vector<pair<char, string>> &g)
{
    if (ans.size() > s.size())
        return;
    if (ans == s)
    {
        check = true;
        return;
    }
    for (auto x : g)
    {
        char c = x.first;
        string d = x.second;
        for (int i = 0; i < ans.size(); i++)
        {
            if (ans[i] != c)
                continue;
                cout<<ans<<endl;
            ans.erase(i, 1);
            cout<<ans<<endl;
            ans.insert(i, d);
            func(s, ans, g);
            ans.erase(i, d.size());
            cout<<string(1,c);
            ans.insert(i, string(1, c));
            if (check)
                return;
        }
    }
}
 int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << endl;
    vector<pair<char, string>> g;
    // g.push_back({'S',"aS"});
    // g.push_back({'S',"Sb"});
    // g.push_back({'S',"ab"});
    int m;
    cout << "Enter the number of regular grammar: ";
    cin >> m;
    cout << endl;
    bool error = true;
    for (int i = 0; i < m; i++)
    {
        char c;
        cout << "Enter the left-hand side for regular grammar "<<i+1<<" : ";
         cin >> c;
        if (c == 'S')
        {
            error = false;
        }
        string s;
        cout << "Enter the right-hand side for regular  grammar "<<i+1<<" : ";     
           cin >> s;
     
     g.push_back({c, s});
        cout << endl;
    }
    if (error)
    {
        cout << "The regular expression does not contain starting symbol S "<<endl;
            return 0;
    }
    string ans = "S";

    func(s, ans, g);
    if (check)
    {
        cout << "String is accepted" << endl;
    }
    else
    {
        cout << "String is not accepted" << endl;
    }
    return 0;
}
