#include<bits/stdc++.h>
using namespace std;
long long int n,m,sum=0,k,t,ans=0,a[1000010];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
	m%=sum;
	for(int i=1;i<n;i++) if(m>=a[i]&&m-a[i]<=a[i+1]) cout<<a[i+1]<<endl<<a[i+1]-m+a[i],i=n; else m-=a[i];
	if(n==1) cout<<"1\n"<<a[1]-m<<"\n";
	return 0;
}
