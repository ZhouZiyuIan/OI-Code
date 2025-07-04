#include<bits/stdc++.h>
using namespace std;

const int MAXN=1e5+7;
const int inf=2e9;

int n,K,vis[30],sum;
char s[MAXN];

struct node {
	int cnt,p;
} q[30];

bool cmp(node x,node y){return x.cnt<y.cnt;}

signed main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%lld",&K);
	for(int i=1;i<=26;i++)
		q[i]={inf,i};
	for(int i=1;i<=n;i++)
	{
		if(q[s[i]-'a'+1].cnt==inf)
			q[s[i]-'a'+1].cnt=1,++sum;
		else
			q[s[i]-'a'+1].cnt++;
	}
	sort(q+1,q+26+1,cmp);
	for(int i=1;i<=26;i++)
	{
		if(K>=q[i].cnt)
		{
			--sum;
			vis[q[i].p]=1;
			K-=q[i].cnt;
		}
	}
	printf("%lld\n",sum);
	for(int i=1;i<=n;i++)
	{
		if(vis[s[i]-'a'+1])
			continue ;
		putchar(s[i]);
	}
	return 0;
}

