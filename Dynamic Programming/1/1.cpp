#include <bits/stdc++.h>
using namespace std;
class sample
{
public:
    int maxProduct(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        int currMax, currMin, prevMax, prevMin, resMax;
        prevMax = nums[0], prevMin = nums[0], resMax = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            currMax = max(max(nums[i], prevMax * nums[i]), prevMin * nums[i]);
            currMin = min(min(nums[i], prevMax * nums[i]), prevMin * nums[i]);
            prevMax = currMax;
            prevMin = currMin;
            resMax = max(resMax, currMax);
        }
        return resMax;
    }
};

int main()
{
    sample g;
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    cout << g.maxProduct(nums);
    return 0;
}