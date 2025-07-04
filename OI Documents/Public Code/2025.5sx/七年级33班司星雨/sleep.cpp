#include<bits/stdc++.h>
using namespace std;
int a[100000],sum,n,t,w;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum+=a[i];
		if(sum==t+2){
			w=i;
		} 
	}
	cout<<w<<" "<<sum-t; 
	return 0;
}
