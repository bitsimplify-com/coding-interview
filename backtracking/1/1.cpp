#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<vector<int>> result;
    vector<int> current;
    void dfs(vector<int>& nums,int start){
        if(current.size()==nums.size()){
            result.push_back(current);
            return;
        }
        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            swap(nums[i],nums[start]);
            dfs(nums,start+1);
            swap(nums[i],nums[start]);
            current.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(nums,0);
        return result;
    }
};

int main()
{
    sample g;
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<vector<int>> soln;
    soln= g.permute(nums);
    for(int i=0;i<soln.size();i++){
        for(int j=0;j<n;j++){
            cout<<soln[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
