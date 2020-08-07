#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    void parent(int label,vector<int>& result,int level){
         result.push_back(label);
         if(level==0)return;
         int p;
         if(level%2!=0)
             p=(pow(2,level)+(pow(2,level+1)-1-label))/2;
         else
            p=(pow(2,level+1)-1-(label-pow(2,level)))/2;
        parent(p,result,level-1);
    }
    vector<int> pathInZigZagTree(int label) {
        if(label==1)return {1};
        vector<int> result;
        int level=log2(label);
        parent(label,result,level);
        reverse(result.begin(),result.end());
        return result;
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> result=g.pathInZigZagTree(n);
    for(auto x:result)cout<<x<<" ";
    return 0;
}
