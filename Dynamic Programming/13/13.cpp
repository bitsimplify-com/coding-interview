#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int longestSubsequenceLength(const vector<int> &A) {
    int n=A.size();
    if(n==0)return 0;
    int dpl[n],dpr[n];
    for(int i=0;i<n;i++){dpl[i]=1;dpr[i]=1;}
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++) if(A[i]>A[j]) dpl[i]=max(dpl[i],dpl[j]+1);
        
    for(int i=n-2;i>=0;i--)
        for(int j=n-1;j>i;j--) if(A[i]>A[j]) dpr[i]=max(dpr[i],dpr[j]+1);
        
    int maxm=0;
    for(int i=0;i<n;i++)maxm=max(dpl[i]+dpr[i],maxm);
    return maxm-1;
    }
};
int main()
{
    sample g;
     int n;
     cin >>n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)cin >> A[i];
    cout<<g.longestSubsequenceLength(A);
    return 0;
}
