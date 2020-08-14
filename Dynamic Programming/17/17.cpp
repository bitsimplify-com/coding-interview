#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<string> result;
    string current;
    void dfs(int i,unordered_map<int,vector<int>>& umap,string s){
        if(i==0){
            current.pop_back();
            result.push_back(current);
            return;
        }
        for(auto x:umap[i]){
            string temp=current;
            current=s.substr(x,i-x)+ " " + current;
            dfs(x,umap,s);
            current=temp;
        }
    }
    vector<string> wordBreak(string A, vector<string>& B) {
        int n=A.size();
        unordered_set<string> uset;
        for(auto x:B)uset.insert(x);
        vector<bool> dp(n+1,false);
        unordered_map<int,vector<int>> umap;
        dp[0]=true;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && uset.find(A.substr(j,i-j))!=uset.end()){
                    dp[i]=true;
                    umap[i].push_back(j);
                }
            }
        }
        result.clear();
        if(!dp[n])return result;
        current="";
        dfs(n,umap,A);
        sort(result.begin(),result.end());
        return result;
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
    vector<string> result=g.wordBreak(s,A);
    for(auto x:result)cout<<x<<"\n";
    return 0;
}
