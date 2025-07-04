#include<bits/stdc++.h>
using namespace std;
char aa[100010],cc[150];
int bb[150];
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	int a,b,c=0,k='a',y=26;
	scanf("%s",aa);
	b=strlen(aa);
	for(int i='a';i<='z';i++) cc[i]=k++;
	while(c<b)
	{
		bb[aa[c]]++;
		c++;
	}
	for(int i='a';i<='z';i++)
	{
		int m=10000000,n;
		for(int j=i;j<='z';j++)
		{
			if(bb[j]<=m)
			{
				m=bb[j];
				n=j;	
			}
		}
		swap(bb[i],bb[n]);
		swap(cc[i],cc[n]);
	}
	scanf("%d",&a);
	c='a';
	while(c<='z')
	{
		if(a>=bb[c])
		{
			a-=bb[c];
			bb[c]=0;
			y--;
		}
		else break;
		c++;
	}
	printf("%d\n",y);
	c=0;
	while(c<b)
	{
		if(bb[cc[aa[c]]]!=0) printf("%c",aa[c]);
		c++;
	}
	return 0;
}
