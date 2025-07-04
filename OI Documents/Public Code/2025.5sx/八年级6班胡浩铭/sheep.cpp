#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN=2e3+7;
const int MOD=1e9+7;

int a[MAXN],ans,vis[MAXN],n;

int qpow(int A,int B)
{
	int res=1;
	while(B)
	{
		if(B&1)
			res=res*A%MOD;
		A=A*A%MOD;
		B>>=1;
	}
	return res;
}

void dfs(int t)
{
//	cout<<t<<endl;
	if(t>n)
	{
		++ans;
		ans%=MOD;
		return ;
	}
	if(a[t]>0)
	{
		dfs(t+1);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i] or i==t)
			continue ;
		vis[i]=1;
		dfs(t+1);
		vis[i]=0;
	}
	return ;
}

signed main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]!=-1)
			vis[a[i]]=1;
	}
	dfs(1);
	printf("%lld",ans);
	return 0;
}
