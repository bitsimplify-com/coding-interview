#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][10],col[9][10],cube[3][3][10];
        memset(row,false,sizeof(row));
        memset(col,false,sizeof(col));
        memset(cube,false,sizeof(cube));
        for(int i=0;i<9;i++)
            for(int j=0;j<9;j++)
                if(board[i][j]!='.'){
                    char x=board[i][j];
                    if(row[i][x-'0'] || col[j][x-'0'] || cube[i/3][j/3][x-'0']) return false;
                    row[i][x-'0']=col[j][x-'0']=cube[i/3][j/3][x-'0']=true;
                }
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
    cout<<g.isValidSudoku(A);
    return 0;
}
