#include<bits/stdc++.h>
using namespace std;
long long n,y,a[1005],tmp,ans;
map<long long,int>vis;
int main()
{
	freopen("picnic.in","r","stdin");
	freopen("picnic.out","w","stdout");
	scanf("%lld%lld",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			tmp=a[i]-a[j];
			if(tmp<0) tmp*=(-1);
			if(!vis[tmp])
			{
				vis[tmp]=1;
				ans++;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
