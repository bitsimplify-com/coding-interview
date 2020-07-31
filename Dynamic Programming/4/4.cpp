#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length(),l=text2.length();
        if(n==0 || l==0)
            return 0;
        int dp[n+1][l+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=l;j++){
                if(i==0 || j==0)
                dp[i][j]=0;
                else{
                    if(text1[i-1]==text2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n][l];
    }
};

int main()
{
    sample g;
    string s,t;
    cin>>s>>t;
    cout<<g.longestCommonSubsequence(s,t);
    return 0;
}
