#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int n=A.size(),l=A[0].size(),minm=105;
        int dp[n][l];
        for(int i=0;i<n;i++){
            for(int j=0;j<l;j++){
                if(i==0) dp[i][j]=A[i][j];
                else dp[i][j]=min(dp[i-1][j],min(dp[i-1][max(0,j-1)],dp[i-1][min(l-1,j+1)]))+A[i][j];
                if(i==n-1) minm=min(minm,dp[i][j]);
            }
        }
        return minm;
    }
};
int main()
{
    sample g;
    int n,l;
    cin >>n>>l;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++){
        for(int j=0;j<l;j++){
            int a;
            cin>>a;
            nums[i].push_back(a);
        }
    }
    cout<<g.minFallingPathSum(nums);
    return 0;
}
