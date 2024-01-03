#include<bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

bool isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int main() {
    cout<<"Enter the Arithematic Expression:- \n";
    string str;
    cin>>str;

    int fl=0;
    for(int i=0;i<str.size()-1;i++)
    {
       if(str[i]==str[i+1]&&isOperator(str[i])){
        fl=1;
        break;
       }
    }
    if(str[0] == '+' || str[0] == '-' || isOperand(str[0])) {
        for(int i=1; i<str.size(); i++) {
            if(isOperator(str[i])) {
                if((i == str.size()-1) || isOperator(str[i+1])) {
                    fl=1;
                    break;
                }
            }
        }
    }
    else {
        fl=1;
    }

    if(fl) {
        cout<<"Not a valid arithematic expression \n";
    }
    else {
        cout<<"valid arithematic expression \n";
    }
    return 0;
}
