#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int minimumTotal(vector<vector<int>>& T) {
        vector<int> dp(T[T.size()-1]);
        for(int i=T.size()-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                dp[j]=min(dp[j],dp[j+1])+T[i][j];
            }
        }
        return dp[0];
    }
};

int main()
{
    sample g;
    int N;
    cin>>N;
    vector<vector<int>> triangle(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            int a;
            cin>>a;
            triangle[i].push_back(a);
        }
    }
    int soln= g.minimumTotal(triangle);
    int soln= g.minimumTotal(triangle);
    cout<<soln<<"\n";
    return 0;
}
