#include<iostream>
#include<algorithm>
using namespace std;

	int main(){
		int n;
		cin>>n;
		int a[n];
			for(int i=0;i<n;i++){
				cin>>a[i];
			}
		int key;
		cin>>key;
		cout<<upper_bound(a,a+n,key)-lower_bound(a,a+n,key)<<endl;	
	}
