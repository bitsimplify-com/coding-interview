#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int obstacles,res;
    void dfs(vector<vector<int>>& grid,int i,int j){
        int m=grid.size(),n=grid[0].size();
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]==-1)return;
        
        if(grid[i][j]==2){
            if(obstacles==0)res++;
            return;
        }
        int x=grid[i][j];
        grid[i][j]=-1;
        if(x!=1)obstacles--;
        
        if(i+1<m && grid[i+1][j]!=-1)dfs(grid,i+1,j);
        if(i-1>=0 && grid[i-1][j]!=-1)dfs(grid,i-1,j);
        if(j+1<n && grid[i][j+1]!=-1)dfs(grid,i,j+1);
        if(j-1>=0 && grid[i][j-1]!=-1)dfs(grid,i,j-1);
        
        grid[i][j]=x;
        if(x!=1)obstacles++;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        res=0;
        obstacles=0;
        for(auto x:grid)
            for(auto y:x)
                if(y==0)obstacles++;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)dfs(grid,i,j);
            }
        }
        return res;
    }
};
int main()
{
    sample g;
     int n,m;
     cin >>n>>m;
     vector<vector<int>> A(n,vector<int> (m));
    for (int i = 0; i < n; i++)for(int j=0;j<m;j++)cin >> A[i][j];
    cout<<g.uniquePathsIII(A);
    return 0;
}
