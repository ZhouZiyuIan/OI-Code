#include<bits/stdc++.h>
using namespace std;
long long n,t;
long long x[100000+1];
long long s=0;
long long ans=0,cnt=0,b;
int main()
{
    freopen("simpleA.in","r",stdin);
    freopen("simpleA.out","r",stdout);
	scanf("%lld%lld",&n,&t);
	for(long long i=0;i<n;i++)
	{
		scanf("%lld",&x[i]);
	}
	while(s<t)
	{
		s++;
		if(s==x[cnt])
		{
	    	ans+=x[cnt];
	    	cnt++;	
		}
	}
	b=ans-t;
	printf("%lld %lld",cnt,b);
	return 0;//shisaijiayou
}
