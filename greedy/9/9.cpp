#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int jump(vector<int>& nums) {
        int currMax=0,currEnd=0,jumps=0;
        for(int i=0;i<nums.size()-1;i++){
            currMax=max(currMax,i+nums[i]);
            if(i==currEnd){
                jumps++;
                currEnd=currMax;
            }
        }
        return jumps;
    }
};

int main()
{
    sample g;
     int n;
     cin>>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
     cout<<g.jump(A);
    return 0;
}
