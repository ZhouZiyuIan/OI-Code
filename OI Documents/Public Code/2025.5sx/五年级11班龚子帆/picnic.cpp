#include<bits/stdc++.h>
using namespace std;
int s[1000200],t[100020],sum,n,y;
int main()
{
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&t[i]); 
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			double k=(t[j]-t[i])*y*1.0/2*10;
			s[int(k)]++;
		}
	}
	for(int i=1;i<=100000;i++)
	{
		if(s[i*5]>0)
		{
			sum++;
		}
	}
	printf("%d",sum);
	return 0;
}
