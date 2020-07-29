#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        unordered_map<int,int> umap;
        stack<int> s;
        for(int i=0;i<T.size();i++){
            while(!s.empty() && T[s.top()]<T[i]){
                int x=s.top();
                s.pop();
                umap[x]=i;
            }
            s.push(i);
            umap[i]=0;
        }
        for(int i=0;i<T.size();i++){
            if(umap[i]==0)res.push_back(0);
            else res.push_back(umap[i]-i);
        }
        return res;
    }
};

int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> T(n);
    for (int i = 0; i < n; i++)
    {
        cin >> T[i];
    }
    vector<int> result= g.dailyTemperatures(T);
    for(auto x:result)cout<<x<<" ";
    return 0;
}
