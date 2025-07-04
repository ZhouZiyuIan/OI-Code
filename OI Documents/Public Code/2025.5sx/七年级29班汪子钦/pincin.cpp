#include<bits/stdc++.h>
using namespace std;
long long a,b,c[3000],d[2206050],e=0,f=0,g=0,h=0;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&a,&b);
	for(long long i=1;i<=a;i++)
	{
		scanf("%lld",&c[i]);
	}
	for(long long i=1;i<=a;i++)
	{
		for(long long j=i+1;j<=a;j++)
		{
			e++;
			d[e]=abs(c[i]-c[j]);
		}
	}
	sort(d+1,d+1+e);
	for(long long i=1;i<=e;i++)
	{
		if(d[i]!=g&&d[i]!=0)
		{
			g=d[i];
			h++;
		}
	}	
	printf("%lld",h);
	return 0;
}
