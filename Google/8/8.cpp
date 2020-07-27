#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    double dp[26][26][101];
    double dfs(int N,int K,int r,int c){
        if(r<0 || r>=N || c<0 || c>=N){
            return 0;
        }    
        if(K==0){
            return 1.00000;
        }
        if(dp[r][c][K]!=0)return dp[r][c][K];
        int R[]={1,1,2,2,-1,-1,-2,-2};
        int C[]={2,-2,1,-1,2,-2,1,-1};
        double prob=0;
        for(int i=0;i<8;i++){
            int row=r+R[i],col=c+C[i];
            prob+=0.125*dfs(N,K-1,row,col);
        }
        dp[r][c][K]=prob;
        return prob;
    }
    double knightProbability(int N, int K, int r, int c) {
        return dfs(N,K,r,c);
    }
};

int main()
{
    sample g;
    int N,K,r,c;
    cin>>N>>K>>r>>c;
    double soln;
    soln= g.knightProbability(N,K,r,c);
    cout<<soln<<"\n";
    return 0;
}
