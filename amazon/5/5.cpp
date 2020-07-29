#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int scoreOfParentheses(string S) {
        stack<int> stk;
        stk.push(0);
        for(auto x:S){
            if(x=='('){
                stk.push(0);
            }
            else{
                int temp=stk.top();
                stk.pop();
                if(temp>0){
                    stk.top()+=temp*2;
                }
                else{
                    stk.top()+=1;
                }
            }
        }
        return stk.top();
    }
};

int main()
{
    sample g;
    string s;
    cin>>s;
    cout << g.scoreOfParentheses(s);
    return 0;
}
