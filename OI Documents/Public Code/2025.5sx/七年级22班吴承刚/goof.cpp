#include<bits/stdc++.h>
using namespace std;
char a[100005];
int k,len,sum[55],tmp,ans=0;
int vis[55];
struct node
{
	int sum,id;
}s[100005];
bool cmp(node x,node y)
{
	return x.sum<y.sum;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",a+1);
	scanf("%d",&k);
	len=strlen(a+1);
	if(len<=k)
	{
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=26;i++)
	{
		vis[i]=1;
	}
	for(int i=1;i<=len;i++)
	{
		s[a[i]-'a'+1].sum++;
		s[a[i]-'a'+1].id=a[i]-'a'+1;
	}
	sort(s+1,s+26+1,cmp);
	for(int i=1;i<=26;i++)
	{
		if(s[i].sum==0)
		{
			vis[s[i].id]=0;
			continue;
		}
		if(tmp+s[i].sum<=k)
		{
			vis[s[i].id]=0;
			tmp+=s[i].sum;
		}
	}
	for(int i=1;i<=26;i++)
	{
		if(vis[s[i].id]==1)
		{
			ans++;
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=len;i++)
	{
		if(vis[a[i]-'a'+1]==1)
		{
			printf("%c",a[i]);
		}
	}
	return 0;
}
