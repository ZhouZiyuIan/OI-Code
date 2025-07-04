#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	int a,b,c[10010],n,m=0;
	double d[10010];
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		scanf("%d",&c[i]);
	}
	for(int i=1;i<=a;i++)
	{	
		if(c[i]<0)
		{
			d[i]=-c[i]*b/2;
		}
		if(c[i]>=0)
		{
			d[i]=c[i]*b/2;
		}
		if(i>1&&d[i]!=d[i])
		{
			n+=1;
		}
		d[i]=0;
	}
	printf("%d",m);
	return 0;
}
