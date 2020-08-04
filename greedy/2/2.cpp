#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<int,int> umap;
        vector<int> result;
        for(int i=0;i<S.length();i++)umap[S[i]]=i;
        int end=INT_MIN,ci=-1;
        for(int i=0;i<S.length();i++){
            if(umap[S[i]]>end)end=umap[S[i]];
            if(i==end){
                result.push_back(i-ci);
                ci=i;
                end=INT_MIN;
            }
        }
        return result;
    }
};
int main()
{
    sample g;
    string s;
    cin>>s;
     vector<int> result=g.partitionLabels(s);
    for(auto x:result)cout<<x<<" ";
    return 0;
}
