#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n;
int a[N];
bool bz[N];
int ans;
inline void dfs(int x)
{
	if(x==n+1)
	{
		ans++;
		return;
	}
	if(a[x]!=-1)
	{
		dfs(x+1);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(i==x) continue;
		if(bz[i]) continue;
		bz[i]=1;
		dfs(x+1);
		bz[i]=0;
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
		if(a[i]!=-1) bz[a[i]]=1;
	}
	dfs(1);
	cout<<ans;
}
