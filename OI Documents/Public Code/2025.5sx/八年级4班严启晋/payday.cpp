#include<bits/stdc++.h>
using namespace std;
long long t,n,s,l[200005],r[200005],k[200005],mx;
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
bool check(long long o)
{
	long long num=0,sum=0;
	for(int i=1;i<=n;i++)num+=r[i]>=o;
	if(num<(n+1)/2) return 0;
	for(int i=1;i<=n;i++)
	{
		if(r[i]>=o)
		{
			sum+=max(l[i],o);
		}
		else sum+=l[i];
	}
	return sum<=s;
	
}
int main()
{
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	read(t);
	while(t--)
	{
		mx=0;
		read(n);read(s);
		for(int i=1;i<=n;i++) read(l[i]),read(r[i]),mx=max(mx,r[i]),k[i]=l[i];
		sort(k+1,k+1+n);
		long long ll=k[n+1>>1],rr=mx,mid,ans;
		while(ll<=rr)
		{
			mid=ll+rr>>1;
			if(check(mid))
			{
				ans=mid;
				ll=mid+1;
			}
			else rr=mid-1;
		}
		printf("%lld\n",ans);
	}
	return 0;
}
