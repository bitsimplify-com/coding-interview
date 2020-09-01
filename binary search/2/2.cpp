#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
        int m=A.size(),n=B.size();
        if(m>n)return findMedianSortedArrays(B,A);
        int left=0,right=m,i,j,mid=(m+n+1)/2,num1,num2;
        while(left<=right){
            i=(left+right)/2;
            j=mid-i;
            if(j>0 && i<m && B[j-1]>A[i])left=i+1;
            else if(i>0 && j<n && A[i-1]>B[j]) right=i-1;
            else{
                if(i==0)num1=B[j-1];
                else if(j==0)num1=A[i-1];
                else num1=max(B[j-1],A[i-1]);
                break;
            }
        }
        if((m+n)%2!=0)return num1;
        if(i==m)num2=B[j];
        else if (j==n)num2=A[i];
        else num2=min(B[j],A[i]);
        return (num1+num2)*1.0/2*1.0;
    }
};
int main()
{
    sample g;
     int n,m;
     cin>>n>>m;
    vector<int> A(n),B(m);
    for (int i = 0; i < n; i++)cin >> A[i];
    for (int i = 0; i < m; i++)cin >> B[i];
     cout<<g.findMedianSortedArrays(A,B);
    return 0;
}
