#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    vector<int> countBits(int num) {
        vector<int> result(num+1,0);
        for(int i=1;i<=num;i++){
            if(i%2==0)
                result[i]=result[i/2];
            else
                result[i]=result[i-1]+1;
        }
        return result;
    }
};

int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> result=g.countBits(n);
    for(auto x:result)cout<<x<<" ";
    return 0;
}
