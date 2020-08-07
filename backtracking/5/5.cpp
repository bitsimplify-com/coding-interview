#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int btrk(vector<int>& res,int n){
        if(n<=0)return 1;
        int count=0;
        for(int i=0;i<n;i++){
            if(res[i]%n==0 || n%res[i]==0){
                swap(res[i],res[n-1]);
                count+=btrk(res,n-1);
                swap(res[n-1],res[i]);
            }
        }
        return count;
    }
    int countArrangement(int N) {
        vector<int> res;
        for(int i=1;i<=N;i++)res.push_back(i);
        return btrk(res,N);
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    cout<<g.countArrangement(n);
    return 0;
}
