#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    bool checkIfCanBreak(string s1, string s2) {
        int n=s1.length(),count1=0,count2=0;
        bool f1=false,f2=false;
        vector<int> a(26,0),b(26,0);
        for(int i=0;i<n;i++){
            a[s1[i]-'a']++;
            b[s2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            count1+=a[i];
            count2+=b[i];
            if(count1>count2){
                if(f1)return false;
                f2=true;
            }
            else if(count2>count1){
                if(f2)return false;
                f1=true;
            }
        }
        return true;
    }
};
int main()
{
    sample g;
    string s,t;
    cin>>s>>t;
    cout<<g.checkIfCanBreak(s,t);
    return 0;
}
