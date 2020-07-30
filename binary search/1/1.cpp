#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int findMin(vector<int>& nums) {
        int left=0,right=nums.size()-1;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(nums[mid]>nums[right]){
                left=mid+1;
            }
            else if(nums[mid]<nums[left]){
                left++;
                right=mid;
            }
            else{
                if(nums[left]<nums[right])
                    return nums[left];
                right--;
            }
        }
        return nums[left];
    }
};

int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)cin >> nums[i];
    cout<<g.findMin(nums);
    return 0;
}
