#include <bits/stdc++.h>
using namespace std;
class sample {
public:
int solve(vector<int> &A) {
    int n=A.size(),res=1;
    if(n<=2)return n;
    vector<unordered_map<int,int>> dp(n);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int d=A[j]-A[i];
            if(dp[i][d]!=0)dp[j][d]=dp[i][d]+1;
            else dp[j][d]=2;
            res=max(res,dp[j][d]);
        }
    }
    return res;
}
};
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.solve(A);
    return 0;
}
