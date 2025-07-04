#include<bits/stdc++.h>
using namespace std;
int n,k,vis[150],sum,ans;
char s[100005];
struct word
{
	int z;
	int m;
}w[150];
bool cmp(word a,word b)
{
	return a.m<b.m;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	gets(s+1);
	scanf("%d",&k);
	int n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		if(vis[s[i]]==0)
		{
			vis[s[i]]++;
			w[++sum].z=s[i];
			w[sum].m++;
		}else
		{
			vis[s[i]]++;
			for(int j=1;j<=sum;j++)
			{
				if(w[j].z==s[i])
				{
					w[j].m++;
				}
			}
		}
	} 
	ans=sum;
	sort(w+1,w+sum+1,cmp);
	for(int j=1;j<=sum;j++)
	{
		if(k>w[j].m)
		{
			k-=w[j].m;
			w[j].m=0;
			vis[w[j].z]=0;
			ans--;
		}else if(k==w[j].m)
		{
			vis[w[j].z]-=k;
			w[j].m-=k;
			ans--;
			k=0;
			break;
		}else
		{
			k=0;
			break;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		if(vis[s[i]]>0)
		{
			printf("%c",s[i]);
			vis[s[i]]--;
		}
	}
	 
	return 0;
}

