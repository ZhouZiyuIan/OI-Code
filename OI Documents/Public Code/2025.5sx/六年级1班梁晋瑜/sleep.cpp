#include<bits/stdc++.h>
using namespace std;
long long n,t,p,sum=0,j=0;
long long a[100001];
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	while(sum<t){
		j++;
		sum+=a[j];
		if(sum>=t){
			cout<<j<<endl;
			cout<<sum-t;
			return 0;
		}
		if(j==n) j=0;
	}
	return 0;
} 
