#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int hold=-prices[0],cash=0;
        for(int i=1;i<prices.size();i++){
            cash=max(cash,hold+prices[i]-fee);
            hold=max(hold,cash-prices[i]);
        }
        return cash;
    }
};
int main()
{
    sample g;
     int n,fee;
     cin >>n>>fee;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.maxProfit(A,fee);
    return 0;
}
