#include<bits/stdc++.h>
using namespace std;
long long n,t,x[100010],sum,cnt;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	cnt=t;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&x[i]);
		sum+=x[i];
	}
	cnt=cnt%sum;
	for(int i=1;i<=n;i++)
	{
		if(cnt<=x[i])
		{
			printf("%d\n%lld",i,x[i]-cnt);
			return 0;
		}
		cnt-=x[i];
	}
 } 
