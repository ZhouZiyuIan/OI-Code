#include<bits/stdc++.h>//ÑùÀıÍ¨¹ı 
using namespace std;
int n,t,a[10001],s,i;
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%d",&n,&t);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s+=a[i];
		if(s>=t)
		{
			printf("%d\n%d",i,s-t);
			return 0;
		}
	}
	if(s<t)
	{
		printf("%d\n0",i-2);
	}
} 
