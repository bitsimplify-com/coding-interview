#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<string> result;
    void dfs(string s,int n,int m){
        if(n==0 && m==0){
            result.push_back(s);
            return;
        }
        if(m>0)dfs(s+')',n,m-1);
        if(n>0)dfs(s+'(',n-1,m+1);
    }
    vector<string> generateParenthesis(int n) {
        dfs("",n,0);
        return result;
    }
};

int main()
{
    sample g;
    int n;
    cin>>n;
    vector<string> soln;
    soln= g.generateParenthesis(n);
    for(auto x:soln)cout<<x<<"\n";
    return 0;
}
