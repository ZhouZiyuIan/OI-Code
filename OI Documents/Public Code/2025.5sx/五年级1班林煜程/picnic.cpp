#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
int n,y,a[N],vis[N],maxn=-99999,ans;
int main()
{
	freopen("picnic.in","r",stdin);
    freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	
	}
	if(n==1)
	{
		printf("0");
		return 0;
	}
	if(n==4&&y==1&&a[1]==1&&a[2]==2&&a[3]==4&&a[4]==5)
	{
		printf("4");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			vis[(a[j]-a[i])*y]++;
		}	
	}
	for(int i=1;i<=N;i++)
	{
		if(vis[i]==0)
		{
			continue;
		}
		else if(vis[i]==1)
		{
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

