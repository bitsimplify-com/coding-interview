#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<int> grayCode(int n) {
        vector<int> res={0};
        int k,l;
        if(n==0)return res;
        for(int i=1;i<=n;i++){
            k=pow(2,i-1),l=res.size();
            for(int j=l-1;j>=0;j--) res.push_back(res[j]+k);
        }
        return res;
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> result=g.grayCode(n);
    for(auto x:result) cout<<x<<" ";
    return 0;
}
