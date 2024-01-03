#include<bits/stdc++.h>
using namespace std;

int main () {
    map <string, string> m;
    while (true) {
        string s;
        getline(cin, s);
        if (s == "$") {
            break;
        }
        string var = "";
        string val = "";
        for (int i=0;i<s.size();i++) {
            if (s[i] == ' ') {
                break;
            }
            var += s[i];
        }
        for (int i=s.size()-1;i>=0;i--) {
            if (s[i] == ' ') {
                break;
            }
            val = s[i] + val;
        }
        if (var == val) {
            if (m.count(var) > 0) {
                cout<<m[var]<<"\n";
            }
            else {
                cout<<"used but not defined"<<"\n";
            }
        }
        else {
            if (m.count(var) > 0) {
                cout<<"Redifined"<<"\n";
                m[var] = val;
            }
            else {
                cout<<"Variable declared successfully"<<"\n";
                m[var] = val;
            }
        }
    }
    return 0;
}