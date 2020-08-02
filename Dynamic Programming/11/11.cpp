#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
       vector<int> dp(n+1,0);
       dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
int main()
{
    sample g;
    int n,l;
    cin >>n;
    cout<<g.climbStairs(n);
    return 0;
}
