#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        int maxCount=1;
        unordered_set<int> uset;
        for(auto num:nums) uset.insert(num);
        
        for(auto x:nums){
            if(uset.find(x-1)==uset.end()){
            int n=x,count=1;
            while(uset.find(n+1)!=uset.end()){
                count++;
                n++;
            }
            if(count>maxCount) maxCount=count;
            }
        }
        return maxCount;
    }
};

int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    cout<<g.longestConsecutive(nums);
    return 0;
}
