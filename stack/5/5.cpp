#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int,char>> stk={{0,'#'}};
        for(char c:s){
            if(stk.back().second!=c) stk.push_back(make_pair(1,c));
            else if(++stk.back().first==k) stk.pop_back();
        }
        string res="";
        for(auto x:stk) res.append(x.first,x.second);
        return res;
    }
};

int main()
{
    sample g;
    int k;
    cin >>k;
    string s;
    cin>>s;
    cout<<g.removeDuplicates(s,k);
    return 0;
}
