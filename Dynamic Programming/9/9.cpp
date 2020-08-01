#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int fmin=INT_MAX,smin=INT_MAX,fi,si;
        for(int i=0;i<A.size();i++){
            if(i!=0){
                for(int j=0;j<A[0].size();j++){
                    if(j==fi)A[i][j]+=smin;
                    else A[i][j]+=fmin;
                }
                fmin=INT_MAX;
                smin=INT_MAX;
            }
            for(int j=0;j<A[0].size();j++){
                if(A[i][j]<fmin){
                    smin=fmin;
                    fmin=A[i][j];
                    fi=j;
                }
                else if(A[i][j]<smin) smin=A[i][j];
            }
        }
        return fmin;
    }
};
int main()
{
    sample g;
    int n,l;
    cin >>n>>l;
    vector<vector<int>> nums(n);
    for (int i = 0; i < n; i++){
        for(int j=0;j<l;j++){
            int a;
            cin>>a;
            nums[i].push_back(a);
        }
    }
    cout<<g.minFallingPathSum(nums);
    return 0;
}
