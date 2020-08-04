#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<vector<int>> groupThePeople(vector<int>& G) {
        unordered_map<int,vector<int>>umap;
        vector<vector<int>> result;
        for(int i=0;i<G.size();i++){
            umap[G[i]].push_back(i);
            if(umap[G[i]].size()==G[i]){
                result.push_back(umap[G[i]]);
                umap.erase(G[i]);
            }
        }
        return result;
    }
};
int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
     vector<vector<int>> result=g.groupThePeople(A);
    for(auto x:result){
        for(auto y:x)cout<<y<<" ";
        cout<<"\n";
    }
    return 0;
}
