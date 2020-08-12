#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<vector<int>> soln;
    vector<int> current;
    void bktrk(vector<int>& A,int sum,int tsum,int start){
        if(sum>=tsum){
            if(sum==tsum)soln.push_back(current);
            return;
        }
        unordered_set<int> uset;
        for(int i=start;i<A.size();i++){
            if(uset.find(A[i])!=uset.end())continue;
            uset.insert(A[i]);
            current.push_back(A[i]);
            bktrk(A,sum+A[i],tsum,i+1);
            current.pop_back();
        }
    }
    vector<vector<int> >combinationSum(vector<int> &A, int B) {
        soln.clear();
        current.clear();
        sort(A.begin(),A.end());
        bktrk(A,0,B,0);
        return soln;
    }
};
int main()
{
    sample g;
     int n,m;
     cin >>n>>m;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    vector<vector<int>> result=g.combinationSum(A,m);
    for(auto x:result){
        for(auto y:x)cout<<y<<" ";
        cout<<"\n";
    }
    return 0;
}
