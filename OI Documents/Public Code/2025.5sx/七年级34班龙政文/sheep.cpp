#include<bits/stdc++.h>
using namespace std;
int n,ans,a[2005],vis[2005];
void dfs(int x)
{
	if(x>n)
	{
		ans++;
		ans%=1000000007;
		return;
	}
	if(a[x]==(-1))
	{
		for(int i=1;i<=n;i++)
		{
			if(vis[i]==0 && i!=x)
			{
				vis[i]=1;
				dfs(x+1);
				vis[i]=0;
			}
		}
	}
	else 
	{
		dfs(x+1);	
	}
}
int main()
{
	freopen("sheep.in","r","stdin");
	freopen("sheep.out","w","stdout");
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]!=(-1))	vis[a[i]]=1;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
