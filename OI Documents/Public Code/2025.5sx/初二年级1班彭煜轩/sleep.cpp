#include<bits/stdc++.h>
using namespace std;
long long aa[100010];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	long long a,b,c=1,d=0;
	scanf("%d%d",&a,&b);
	while(c<=a)
	{
		scanf("%d",&aa[c]);
		d+=aa[c];
		c++;
	}
	b%=d;
	c=1;
	while(c<=a)
	{
		b-=aa[c];
		if(b<=0)
		{
			b*=-1;
			break;
		}
		c++;
	}
	printf("%d\n%d",c,b);
	return 0;
}
