#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1])
            maxProfit+=prices[i]-prices[i-1];
        }
        return maxProfit;
    }
};

int main()
{
    sample g;
    int N;
    cin>>N;
    vector<int> prices(N);
    for(int i=0;i<N;i++){
        cin>>prices[i];
    }
    int soln= g.maxProfit(prices);
    cout<<soln<<"\n";
    return 0;
}
