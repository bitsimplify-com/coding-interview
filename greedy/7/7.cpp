#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int minimumSwap(string s1, string s2) {
        int x1=0,y1=0;
        for(int i=0;i<s1.length();i++){
            if(s1[i]==s2[i])continue;
            if(s1[i]=='x')x1++;
            else y1++;
        }
        if((x1+y1)%2!=0)return -1;
        return x1/2 + y1/2 + (x1%2)*2;
    }
};
int main()
{
    sample g;
    string s,t;
    cin>>s>>t;
    cout<<g.minimumSwap(s,t);
    return 0;
}
