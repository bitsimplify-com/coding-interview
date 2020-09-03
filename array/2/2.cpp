#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<vector<int>> threeSum(vector<int>& nums) { 
        int low,high,x;
        vector<vector<int>> res;
        if(nums.size()<3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
                low=i+1;high=nums.size()-1;
                x=-1*nums[i];
                while(low<high){
                    if(nums[low]+nums[high]==x){
                        res.push_back({nums[i],nums[low],nums[high]});
                        do{
                            low++;
                        }while(low<high && nums[low]==nums[low-1]);
                        do{
                            high--;
                        }while(low<high && nums[high]==nums[high+1]);
                    }
                    else if(nums[low]+nums[high]<x){
                       do{
                            low++;
                        }while(low<high && nums[low]==nums[low-1]);
                    }
                    else{
                        do{
                            high--;
                        }while(low<high && nums[high]==nums[high+1]);
                    }
                }
            }
        }
        return res;
    }
};

int main()
{
    sample g;
     int n;
     cin>>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    vector<vector<int>>result =g.threeSum(A);
    for(auto x:result){
        for(auto y:x)cout<<y<<" ";
        cout<<"\n";
    }
    return 0;
}
