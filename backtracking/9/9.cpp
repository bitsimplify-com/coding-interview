#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<vector<int>> result;
    vector<int> current;
    void bktrk(vector<int> &A,int start){
        if(start==A.size())return;
        unordered_set<int> uset;
        for(int i=start;i<A.size();i++){
            if(uset.find(A[i])!=uset.end())continue;
            uset.insert(A[i]);
            current.push_back(A[i]);
            result.push_back(current);
            bktrk(A,i+1);
            current.pop_back();
        }
    }


    vector<vector<int>>subsetsWithDup(vector<int> &A) {
        result.clear();
        current.clear();
        sort(A.begin(),A.end());
        result.push_back({});
        bktrk(A,0);
        return result;
    } 
};
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    vector<vector<int>> result=g.subsetsWithDup(A);
    for(auto x:result){
        for(auto y:x)cout<<y<<" ";
        cout<<"\n";
    }
    return 0;
}
