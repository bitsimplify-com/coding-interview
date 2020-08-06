#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool canConstruct(string s, int k) {
        int n=s.length();
        if(k>n)return false;
        if(k==n)return true;
        bitset<26> odds;
        for(auto x:s) odds.flip(x-'a');
        if(odds.count()<=k)return true;
        return false;
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    string s;
    cin>>s;
    cout<<g.canConstruct(s,n);
    return 0;
}
