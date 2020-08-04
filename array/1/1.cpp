#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr=arr[0],wins=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i]>curr){
                curr=arr[i];
                wins=0;
            }
            if(++wins==k)return curr;
        }
        return curr;
    }
};
int main()
{
    sample g;
    int n,k;
    cin >>n>>k;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.getWinner(A,k);
    return 0;
}
