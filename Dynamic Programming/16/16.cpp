#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int nthUglyNumber(int n) {
         vector<int> dp;
         dp.push_back(1);
         int i=0,j=0,k=0;
         while(dp.size()<n){
             dp.push_back(min(dp[i]*2,min(dp[j]*3,dp[k]*5)));
             if(dp.back()==dp[i]*2)i++;
             if(dp.back()==dp[j]*3)j++;
             if(dp.back()==dp[k]*5)k++;
         }
         return dp.back();
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    cout<<g.nthUglyNumber(n);
    return 0;
}
