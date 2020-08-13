#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool rows[9][10],cols[9][10],cubes[3][3][10];
    void solveSudoku(vector<vector<char>>& board) {
        memset(rows,false,sizeof(rows));
        memset(cols,false,sizeof(cols));
        memset(cubes,false,sizeof(cubes));
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    rows[i][board[i][j]-'0']=true;
                    cols[j][board[i][j]-'0']=true;
                    cubes[i/3][j/3][board[i][j]-'0']=true;
                }
            }
        }
        bktrk(board,0,0);
    }
    bool bktrk(vector<vector<char>>& board,int r,int c){
        if(r==9)return true;
        if(c==9)return bktrk(board,r+1,0);
        if(board[r][c]!='.')return bktrk(board,r,c+1);
        for(char a='1';a<='9';a++){
            if(checkIfinsert(board,r,c,a)){
                board[r][c]=a;
                rows[r][board[r][c]-'0']=cols[c][board[r][c]-'0']=cubes[r/3][c/3][board[r][c]-'0']=true;
                if(bktrk(board,r,c+1))return true;
                rows[r][board[r][c]-'0']=cols[c][board[r][c]-'0']=cubes[r/3][c/3][board[r][c]-'0']=false;
                board[r][c]='.';
            }
        }
        return false;
    }
    bool checkIfinsert(vector<vector<char>>& board,int r,int c,char a){
        if(rows[r][a-'0'])return false;
        if(cols[c][a-'0'])return false;
        if(cubes[r/3][c/3][a-'0'])return false;
        return true;
    }
};
int main()
{
    sample g;
     int n,m;
     cin >>n>>m;
     vector<vector<char>> A(n,vector<char> (m));
    for (int i = 0; i < n; i++)for(int j=0;j<m;j++)cin >> A[i][j];
    vector<vector<char>> result=A;
    g.solveSudoku(result);
    for(auto x:result){
        for(auto y:x)cout<<y<<" ";
        cout<<"\n";
    }
    return 0;
}
