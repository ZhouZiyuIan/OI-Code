#include<cstdio>
#define ll long long
using namespace std;
const int N=2e3+5;
const ll Mod=1e9+7;
int n,a[N],chg[N];
ll ans,sum;
bool bz[N];
ll ksm(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res=res*x%Mod;
		x=x*x%Mod;
		y>>=1; 
	}
	return res;
}
void dfs(int k)
{
	if(k>n)
	{
		ans++;
		return;
	}
	if(a[k]!=-1)
	{
		dfs(k+1);
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			if(bz[i]||k==i) continue;
			bz[i]=1;
			dfs(k+1);
			bz[i]=0;
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
		scanf("%d",&a[i]);
		if(a[i]!=-1)
		{
			bz[a[i]]=1;
			chg[a[i]]=1;
		}
		else sum++;
	}
	if(n<=12)
	{
		dfs(1);
		printf("%lld",ans);
	}
	else
	{
		ans=1;
		for(int i=1;i<=sum;i++)
			ans=ans*i%Mod;
		printf("%lld",ans);
	}
	return 0;
}
