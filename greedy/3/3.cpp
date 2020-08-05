#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>>result;
        sort(people.begin(),people.end(),[](const vector<int>& a,const vector<int>& b){
        return (a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]));
             });
        for(vector<int>& x: people) result.insert(result.begin() + x[1], x);
        return result;
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
     vector<vector<int>> A(n,vector<int> (2));
    for (int i = 0; i < n; i++)cin >> A[i][0]>>A[i][1];
     vector<vector<int>> result=g.reconstructQueue(A);
    for(auto x:result)cout<<x[0]<<" "<<x[1]<<" ";
    return 0;
}
