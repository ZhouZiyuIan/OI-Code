#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t,x[100005],sum[100005],s,tmp=0,id;
int main()
{
	//freopen("sleep.in","r",stdin);
	//freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		sum[i]=sum[i-1]+x[i];
	}
	s=t%sum[n];
	for(int i=1;i<=n;i++)
	{
		if(tmp+x[i]>=s)
		{
			id=i;
			break;
		}
		tmp+=x[i];
	}
	printf("%lld\n%lld",id,sum[id]-s);
	return 0;
}
