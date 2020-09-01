#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int numDecodings(string s) {
        int n=s.size();
        if(!s.size())
            return 1;
        vector<int> dp(n+1);
        dp[n]=1;
        dp[n-1]=(s[n-1]=='0')?0:1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='0')
                dp[i]=0;
            else if(s[i]=='1' || (s[i]=='2' && s[i+1]<='6') ){
                dp[i]=dp[i+1]+dp[i+2];
            }
            else
                dp[i]=dp[i+1];
        }
        return dp[0];
    }
};

int main()
{
    sample g;
     string s;
     cin>>s;
     cout<<g.numDecodings(s);
    return 0;
}
