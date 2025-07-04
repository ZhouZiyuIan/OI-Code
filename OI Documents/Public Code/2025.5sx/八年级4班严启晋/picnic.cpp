#include<bits/stdc++.h>
using namespace std;
long long n,y,x[1005],ans;
map<long long ,bool>s;
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
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	read(n);read(y);
	for(int i=1;i<=n;i++)
	{
		read(x[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(s[abs(x[i]-x[j])]) continue;
			s[abs(x[i]-x[j])]=1;ans++;
			
		}
	}
	printf("%lld",ans);
	return 0;
}
