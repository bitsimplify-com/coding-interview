#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)return false;
        sort(nums.begin(),nums.end());
        unordered_map<int,int> umap;
        for(auto x:nums)umap[x]++;
        for(auto x:nums){
            if(!umap[x])continue;
            for(int i=x;i<x+k;i++) if(!umap[i])return false;
            for(int i=x;i<x+k;i++) umap[i]--;
        }
        return true;
    }
};
int main()
{
    sample g;
     int n,k;
     cin >>n>>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.isPossibleDivide(A,k);
    return 0;
}
