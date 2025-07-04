#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
int n,y,x[N];
ll ans;
map<ll,bool> vis;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++)
	  scanf("%d",&x[i]);
	sort(x+1,x+1+n);
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			ll t=1LL*(x[j]-x[i]);
			if(!vis[t])
			  ans++;
			vis[t]=1;
		}
	}
	printf("%lld",ans);
	return 0;
}

