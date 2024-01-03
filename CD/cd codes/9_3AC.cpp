#include <bits/stdc++.h>
using namespace std;
int prec(string c){
    if (c == "^") return 3;
    else if (c == "/" || c == "*") return 2;
    else if (c == "+" || c == "-") return 1;
    else return -1;
}
bool isInt(string s){
    for (auto it : s){
        if (!(it <= 'z' && it >= 'a')) return false;
    }
    return true;
}
vector<string> infixToPostfix(vector<string> s){
    stack<string> st;
    vector<string> result;
    for (int i = 0; i < s.size(); i++){
        string c = s[i];
        if (isInt(c)) result.push_back(c);
        else if (c == "(") st.push("(");
        else if (c == ")") {
            while (st.top() != "(") {
                result.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else {
            while (!st.empty() && prec(s[i]) <= prec(st.top())) {
                result.push_back(st.top());
                st.pop();
            }
            st.push(c);
        }
    }
    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }
    return result;
}
vector<string> tokenize() {
    int n;
    // cin >> n;
    vector<string> ans;
    string temp;
    string str;
    cin>>str;

    for (int i = 0; i < str.size(); i++) {
        string temp;
        temp+=str[i];
        ans.push_back(temp);
    }
    return ans;
}
 
void get3AddressCodes(vector<string> vec){
    vector<string> stk;
    int x = 0;
    for(auto it: vec){
        if(isInt(it)) stk.push_back(it);
        else{
            string a = *stk.rbegin();
            stk.pop_back();
            string b = *stk.rbegin();
            stk.pop_back();
            x++;
            cout<<"t"<<(x)<<" = "<<b<<" "<<it<<" "<<a<<endl;
            char m = ('0'+x);
            stk.push_back(((string)"t")+m);
        }
    }
}
int main(){
    vector<string> strs, postfx;
    strs = tokenize();
    for (auto it : strs) cout << it << " ";
    cout << endl;
    postfx = infixToPostfix(strs);
    for (auto it : postfx) cout << it << " ";
    cout << endl;
    get3AddressCodes(postfx);
    return 0;
}