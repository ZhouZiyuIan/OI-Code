#include<bits/stdc++.h>
using namespace std;
long long n,t,oto=0,s=0,tot=0,x[10004];
int main()
{
//freopen("sleep.in","r",stdin);
//freopen("sleep.out","r",stdout);	
scanf("%lld%lld",&n,&t);
int u=t;
for(long long i=1;i<=n;i++)
{
	scanf("%lld",&x[i]);
	oto+=x[i]; 
}
if(t<=oto)
{
for(long long i=1;i<=n;i++)
{
	t=t-x[i];
	tot++;
	if(t<=0)
	{
		printf("%lld\n%lld",i,oto-u);
		return 0;
	}	
}	
}
while(t>oto)
{
	t=t-oto;
	s++;
	if(t<=oto)
	{
		break;
	}
}
for(long long i=1;i<=n;i++)
{
	t=t-x[i];
	tot++;
	if(t<=0&&(t+s)/3==1)
	{
		printf("1\n%lld",oto-u);
		return 0;
	}	
	if(t<=0&&(t+s)/3==2)
	{
		printf("2\n%lld",oto-u);
		return 0;
	}	
	if(t<=0&&(t+s)/3==3)
	{
		printf("3\n%lld",oto-u);
		return 0;
	}	
}	
	return 0;
}
