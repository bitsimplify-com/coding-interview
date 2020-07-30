#include <bits/stdc++.h>
using namespace std;
class sample {
public:
    int fact(int n) { 
    return (n == 1 || n == 0) ? 1 : n * fact(n - 1); 
    }
    
    string getPermutation(int n, int k) {
        vector<int> arr(n+1);
        for(int i=0;i<=n;i++)
            arr[i]=i;
        string result="";
        while(n){
            int q=k/fact(n-1);
            int r=k%fact(n-1);
            if(r!=0)
                q++;
            result+=to_string(arr[q]);
            auto it=arr.begin()+q;
            arr.erase(it);
            if(r!=0)
                k=r;
            else
                k=fact(n-1);
            n--;
        }
        return result;
    }
};

int main()
{
    sample g;
    int n,k;
    cin >>n>>k;
    cout<<g.getPermutation(n,k);
    return 0;
}
