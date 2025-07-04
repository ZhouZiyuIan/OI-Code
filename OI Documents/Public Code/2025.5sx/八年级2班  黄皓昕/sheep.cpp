#include<bits/stdc++.h>
using namespace std;
int n,m,v[2005],w[2005],sb;long long ans,mod=1e9+7;
void dfs(int x)
{
	if(x>m)
	{
		ans++;
		ans%mod;
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i]==0 and w[x]!=i)
		{
			v[i]=1;
			dfs(x+1);
			v[i]=0;
		}
	}
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>sb;
		if(sb==-1)
		{
			m++;
			w[m]=i;
		}
		v[sb]=true;
	}
	dfs(1);
	cout<<ans%mod;
}

