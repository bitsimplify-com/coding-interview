#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int i=0,j=0;
        pushed.push_back(-1);
        while(i<pushed.size() && j<popped.size()){
            if(!stk.empty() && stk.top()==popped[j]){
                stk.pop();
                j++;
            }
            else{
                stk.push(pushed[i++]);
            }
        }
        if(j!=popped.size())return false;
        return true;
    }
};

int main()
{
    sample g;
    int n,m;
    cin >>n>>m;
    vector<int> pushed(n),popped(m);
    for (int i = 0; i < n; i++)cin >> pushed[i];
    for (int i = 0; i < m; i++)cin >> popped[i];
    cout<<g.validateStackSequences(pushed,popped);
    return 0;
}
