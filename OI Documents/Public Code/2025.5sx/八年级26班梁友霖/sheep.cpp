#include<bits/stdc++.h>
using namespace std;
int n;
const int N=19;
int a[N];
int bz[N];
long long ans=0;
const long long mod=1e9+7;
void dfs(int x)
{
	if(x==n+1)
	{
		ans++;
		ans%=mod;
		return ;
	}
	if(a[x]!=-1)
	{
		dfs(x+1);
		return ;
	}
	for(int i=1;i<=n;i++)
	{
		if(i!=x&&bz[i]==0)
		{
			bz[i]=1;
			a[x]=i;
			dfs(x+1);
			a[x]=-1;
			bz[i]=0;
		}
	}
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]!=-1)
		bz[a[i]]=1;
	}
dfs(1);
cout<<ans;
	return 0;
}
