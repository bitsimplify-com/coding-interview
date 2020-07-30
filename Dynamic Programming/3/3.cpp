#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int maxProfit(vector<int>& prices) {
        int l=prices.size();
        if(l==0 || l==1)return 0;
        int buy[l+1];
        int sell[l+1];
        for(int i=0;i<=l;i++){
            buy[i]=0;
            sell[i]=0;
        }
        buy[1]=-prices[0];
        for(int i=2;i<=l;i++){
            int price=prices[i-1];
            buy[i]=max(buy[i-1],sell[i-2]-price);
            sell[i]=max(sell[i-1],buy[i-1]+price);
        }
        return sell[l];
    }
};

int main()
{
    sample g;
    int n;
    cin >>n;
    vector<int> prices(n);
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }
    cout<<g.maxProfit(prices);
    return 0;
}
