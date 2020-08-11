#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    stack<int> stk;
	    string res="";
	    for(int i=0;i<=s.length();i++){
	        stk.push(i+1);
	        if(i==s.length() || s[i]=='I'){
	            while(!stk.empty()){
	                res+=to_string(stk.top());
	                stk.pop();
	            }
	        }
	    }
	    cout<<res<<"\n";
	}
	return 0;
}
