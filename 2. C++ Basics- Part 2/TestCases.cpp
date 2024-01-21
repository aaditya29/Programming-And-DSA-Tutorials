#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;//t is variable for test cases
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;++i){
			for(int j=1; j<=i;++j){
				cout<<"*";
			}
			cout<<endl;
		}
	}
}