#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int trap(vector<int>& height) {
        int left=0,right=height.size()-1,maxl=0,maxr=0,res=0;
        while(left<=right){
            if(height[left]<=height[right]){
                maxl=max(maxl,height[left]);
                res+=maxl-height[left++];
            }
            else{
                maxr=max(maxr,height[right]);
                res+=maxr-height[right--];
            }
        }
        return res;
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.trap(A);
    return 0;
}
