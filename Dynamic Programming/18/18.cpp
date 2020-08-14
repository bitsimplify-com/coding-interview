#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_set<string> uset;
        for(auto x:wordDict) uset.insert(x);
        vector<bool> dp(n+1,false);
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=i-1;j>=0;j--){
                if(dp[j] && uset.find(s.substr(j,i-j))!=uset.end()){
                    dp[i]=true;
                    break;
                }
            }   
        }
        return dp[n];
    }
};
int main()
{
    sample g;
     int n;
     string s;
     cin>>s>>n;
    vector<string> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
     cout<<g.wordBreak(s,A);
    return 0;
}
