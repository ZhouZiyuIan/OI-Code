#include<bits/stdc++.h>
using namespace std;
long long n,ans,a[200005][5],s[200005],mid,t,p,ss[200005];
void dfs(long long x,long long y)
{
	if(x>n)
	{
		for(int i=1;i<=n;i++)
		{
			ss[i]=s[i];
		}
		sort(ss+1,ss+1+n);
		ans=max(ans,ss[mid]);
		return;
	}
	for(int i=a[x][1];i<=a[x][2];i++)
	{
		if(y>=i)
		{
			s[x]=i;
			dfs(x+1,y-i);
		}
	}
}
int main()
{
	freopen("payday.in","r","stdin");
	freopen("payday.out","w","stdout");
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&p);
		mid=n/2+1;
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d",&a[i][1],&a[i][2]);
		}
		dfs(1,p);
		printf("%d\n",ans);
	}
	return 0;
}
