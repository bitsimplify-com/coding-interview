#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        string res="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') stk.push(res.size());
            else if(s[i]==')'){
                int t=stk.top();
                stk.pop();
                reverse(res.begin()+t,res.end());
            }
            else res+=s[i];
        }
        return res;
    }
};

int main()
{
    sample g;
    string s;
    cin>>s;
    cout<<g.reverseParentheses(s);
    return 0;
}
