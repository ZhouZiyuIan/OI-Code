#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int n,t,sum,a[N],id,x;
signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];t%=sum;sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i];
		if(sum>=t){id=i;x=(sum-t);break;}
	}
	cout<<id<<'\n'<<x;
	return 0;
} 
