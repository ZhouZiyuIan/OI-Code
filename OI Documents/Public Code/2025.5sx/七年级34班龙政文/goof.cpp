#include<bits/stdc++.h>
using namespace std;
int n,k,vis[300];
struct w{
	int num,tot;
}v[50];
char s[100005];
bool cmp(w a,w b)
{
	return a.tot<b.tot;
}
int main()
{
	freopen("goof.in","r","stdin");
	freopen("goof.out","w","stdout");
	scanf("%s",s+1);
	n=strlen(s+1);
	scanf("%d",&k);
	for(int i=1;i<=n;i++)
	{
		if(!vis[s[i]-96])	vis[0]++;
		vis[s[i]-96]=1;
		v[s[i]-96].num=s[i]-96;
		v[s[i]-96].tot++;
	}
	sort(v+1,v+27,cmp);
	for(int i=1;i<=30;i++)
	{
		if(k>=v[i].tot && v[i].tot!=0)
		{
			k-=v[i].tot;
			vis[v[i].num]=0;
			vis[0]--;
		}
	}
	printf("%d\n",vis[0]);
	for(int i=1;i<=n;i++)
	{
		if(vis[s[i]-96]!=0)
		{
			printf("%c",s[i]);
		}
	}
	return 0;
}
