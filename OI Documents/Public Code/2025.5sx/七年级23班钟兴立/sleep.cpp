#include<bits/stdc++.h>
using namespace std;
long long n,t,tmp,sum,k,x[500005];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		sum+=x[i];
	}
	k=t%sum;
	if(k==0)
	{
		printf("%d\n0",n);
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		k-=x[i];
		if(k<=0)
		{
			printf("%d\n",i);
			tmp=0-k;
			printf("%d",tmp);
			return 0;
		}
	}
}
