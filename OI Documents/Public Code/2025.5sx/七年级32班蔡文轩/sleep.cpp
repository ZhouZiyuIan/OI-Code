#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	int m=0,n,a,b,c[10010],d=0;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=a;i++)
	{
		d=b-c[i];
		if(b-c[i]<c[i])
		{
			m=c[i]-b;
		}
	}
	for(int i=1;i<=a;i++)
	{
		printf("%d %d",i,m);
	}
}
