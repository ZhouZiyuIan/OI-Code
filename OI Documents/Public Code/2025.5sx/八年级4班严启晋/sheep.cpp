#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
long long n,a[2005],ans=1,num;
bool vis[2005];
void read(long long &x)
{
	x=0;
	long long w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=w;
}
int main()
{
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++)
	{
		read(a[i]);num+=a[i]==-1;
		if(a[i]>0)vis[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]<0)
		{
			ans=ans*max(1ll,num-(vis[i]==0))%mod;
			num--;
		}
	}
	
	printf("%lld",ans);
	return 0;
}
