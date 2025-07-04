#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,num[30],ans,sum,wz[30];
char ch[N];
void rd()
{
	char c=getchar();
	while(!(c>='a'&&c<='z')) c=getchar();
	while(c>='a'&&c<='z')
	{
		ch[++n]=c;
		num[c-96]++;
		c=getchar();
	}
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	rd();
	scanf("%d",&m);
	for(int i=1;i<=26;i++)
		wz[i]=i;
	for(int i=1;i<=26;i++)
	{
		for(int j=i+1;j<=26;j++)
		{
			if(num[i]>num[j])
			{
				swap(num[i],num[j]);
				swap(wz[i],wz[j]);
			}
		}
	}
	sum=0;
	ans=26;
	for(int i=1;i<=26;i++)
	{
		if(num[i]==0)
		{
			ans--;
			continue;
		}
		sum+=num[i];
		if(sum>m) break;
		ans--;
		for(int j=1;j<=n;j++)
		{
			if(ch[j]==wz[i]+96)
				ch[j]=0;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++)
		if(ch[i]>='a'&&ch[i]<='z') printf("%c",ch[i]);
	return 0;
}
