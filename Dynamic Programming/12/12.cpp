#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int calculateMinimumHP(vector<vector<int>>& D) {
        int n=D.size(),m=D[0].size();
        for(int i=n-1;i>=0;i--)
            for(int j=m-1;j>=0;j--){
                if(i==n-1 && j==m-1) D[i][j]=max(1,1-D[i][j]);
                else if(i==n-1) D[i][j]=max(1,D[i][j+1]-D[i][j]);
                else if(j==m-1) D[i][j]=max(1,D[i+1][j]-D[i][j]);
                else D[i][j]=max(1,min(D[i][j+1],D[i+1][j])-D[i][j]);
            }
        
        return D[0][0];
    }
};
int main()
{
    sample g;
     int n,m;
     cin >>n>>m;
     vector<vector<int>> A(n,vector<int> (m));
    for (int i = 0; i < n; i++)for(int j=0;j<m;j++)cin >> A[i][j];
    cout<<g.calculateMinimumHP(A);
    return 0;
}
