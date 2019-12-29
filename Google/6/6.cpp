#include<bits/stdc++.h> 
using namespace std; 
int countWays(int n, int k) 
{ 
    int total = k; 
    int mod = 1000000007; 
  
    int same = 0, diff = k; 
  
    for (int i = 2; i <= n; i++) 
    { 
        same = diff; 
        diff = total * (k-1); 
        diff = diff % mod; 
        total = (same + diff) % mod; 
    } 
  
    return total; 
} 
  
int main() 
{ 
    int n,k;
    cin>>n>>k;
    cout << countWays(n, k) << endl; 
    return 0; 
} 