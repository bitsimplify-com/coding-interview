#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int m=A.size(),n=B.size();
        if(n==0 || m==0)return 0;
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        int maxm=0;
        for(int i=0;i<=m;i++){
            for(int j=0;j<=n;j++){
                if(i==0 || j==0) dp[i][j]=0;
                else{
                    if(A[i-1]==B[j-1]){
                        dp[i][j]=1+dp[i-1][j-1];
                        maxm=max(maxm,dp[i][j]);
                    }
                    else dp[i][j]=0;
                }
            }
        }
        return maxm;
    }
};
int main()
{
    sample g;
    int n,l;
    cin >>n>>l;
    vector<int> A(n);
    vector<int> B(l);
    for (int i = 0; i < n; i++)cin >> A[i];
    for (int i = 0; i < l; i++)cin >> B[i];
    cout<<g.findLength(A,B);
    return 0;
}
