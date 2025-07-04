#include<bits/stdc++.h>
using namespace std;
long long n,t,x[100005],sum;
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
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	read(n);read(t);
	for(int i=1;i<=n;i++)
	{
		read(x[i]);sum+=x[i];
	}
	t=(t-1)%sum+1;
	sum=0;
	for(int i=1;i<=n;i++)
	{
		sum+=x[i];
		if(sum>=t) {printf("%d\n%lld",i,sum-t);return 0;}
	}
	return 0;
}
