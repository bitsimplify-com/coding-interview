#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool isMatch(string A, string B) {
        int i=0,j=0,m=A.size(),n=B.size();
    bool dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 && j==0)dp[i][j]=true;
            else if(i==0 && B[j-1]=='*')dp[i][j]=dp[i][j-1];
            else if(i==0)dp[i][j]=false;
            else if(j==0)dp[i][j]=false;
            else{
                if(A[i-1]==B[j-1] || B[j-1]=='?')dp[i][j]=dp[i-1][j-1];
                else if(B[j-1]=='*')dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else dp[i][j]=false;
            }
        }
    }
    return dp[m][n];
    }
};

int main()
{
    sample g;
    string A,B;
    cin>>A,B;
    bool soln= g.isMatch(A,B);
    cout<<soln<<"\n";
    return 0;
}
