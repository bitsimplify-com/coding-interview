#include <bits/stdc++.h>
using namespace std;
class sample {
public:
int add(int a,int b){
    int M=1000007;
    return ((a%M)+(b%M))%M;
}
int coinchange2(vector<int> &A, int B) {
    vector<int> dp(B+1,0);
    dp[0]=1;
    for(int i=0;i<A.size();i++)
        for(int j=0;j<=B && j+A[i]<=B;j++)
            if(dp[j]>0) dp[j+A[i]]=add(dp[j],dp[j+A[i]]);
    return dp[B];
}
};
int main()
{
    sample g;
     int n,m;
     cin >>n>>m;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.coinchange2(A,m);
    return 0;
}
