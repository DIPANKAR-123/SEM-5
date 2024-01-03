#include<bits/stdc++.h>
using namespace std;
int cnt=0;
bool ch(char c)
{
         if((c>='a'&&c<='z')||(c>='A'&&c<='Z'))
             {
                  return false;
             }
             return true;
}
vector<bool> vis(1e5);
stack<string> ft;
string tad(string &s,int &in)
{
      stack<char> st;
      while(ch(s[in]))
      {
         st.push(s[in]);
         --in;
      }
      string pr="";
      pr.push_back(s[in]);
      while(in>0)
      {
         --in;
           string nx="";
          if(ch(s[in]))
          {
             nx=tad(s,in);
             break;
          }
          else
          nx.push_back(s[in]);
          nx.push_back(st.top());
          st.pop();
          nx+=pr;
          cout<<"t"<<cnt<<"="<<nx<<endl;
          pr="t";
          pr.push_back(char('0'+cnt));
          ++cnt;
      }
      while(!st.empty())
      {
        string nx=ft.top();
         ft.pop();
        
          nx.push_back(st.top());
          st.pop();
          nx+=pr;
          cout<<"t"<<cnt<<"="<<nx<<endl;
          pr="t";
          pr.push_back(char('0'+cnt));
          ++cnt;
      }
      ft.push(pr);
      cout<<pr<<" hrll "<<endl;
      
      return pr;


}
int pr(char s)
    {
         if(s=='-')
         return 1;
         if(s=='+')
         return 1;
           if(s=='*')
         return 2;
         if(s=='/')
         return 2;
          return 5;
         
    }
    // Function to convert an infix expression to a postfix expression.
    string infixToPostfix(string s) {
        string ot="";
        stack<char> temp;
        for(int i=0;i<s.size();i++)
        {
             if((s[i]>='a'&&s[i]<='z')||(s[i]>='A'&&s[i]<='Z'))
             {
                  ot+=s[i];
                  continue;
             }
             if(s[i]=='(')
             {
                 temp.push('(');
                 continue;
             }
             if(s[i]==')')
             {
                 while(temp.top()!='(')
                 {
                     ot.push_back(temp.top());
                     temp.pop();
                 }
                 temp.pop();
                 continue;
             }
             while(!temp.empty()&&temp.top()!='('&&pr(temp.top())>=pr(s[i]))
             {
                   ot.push_back(temp.top());
                   temp.pop();
             }
             temp.push(s[i]);
             
        }
         while(!temp.empty())
             {
                   ot.push_back(temp.top());
                   temp.pop();
             }
        return ot;
        // Your code here
    }
int main()
{
       string exp;
       cin>>exp;
       exp=infixToPostfix(exp);
       cout<<exp<<endl;
       int n=exp.length()-1;
       cout<<tad(exp,n)<<endl;
       


}