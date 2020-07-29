#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int minAddToMakeValid(string S) {
        stack<int> s;
        for(auto x:S){
            if(x=='(') s.push(x);
            else{
                if(!s.empty() && s.top()=='(') s.pop();
                else s.push(x);
            }
        }
        return s.size();
    }
};

int main()
{
    sample g;
    string s;
    cin>>s;
    cout<<g.minAddToMakeValid(s);
    return 0;
}
