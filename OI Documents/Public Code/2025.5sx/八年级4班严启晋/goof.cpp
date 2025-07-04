#include<bits/stdc++.h>
using namespace std;
long long k,cnt[100],num;
char s[100005];
bool vis[100];
void read(long long &x)
{
	x=0;
	long long w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	x*=w;
}
int main()
{
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",s+1);
	read(k);
	for(int i=1;s[i];i++)
	{
		if(!cnt[s[i]-'a']) num++;
		cnt[s[i]-'a']++;
	}
	for(int i=0;i<='z'-'a';i++)
	{
		long long mn=1e18,id=0;
		for(int j=0;j<='z'-'a';j++)
		{
			if(cnt[j]<=mn&&cnt[j]) mn=cnt[j],id=j;
		}
		if(k>=mn) k-=mn;
		else break;
		vis[id]=1;
		num--;
		cnt[id]=0;
	}
	printf("%lld\n",num);
	for(int i=1;s[i];i++)
	{
		if(vis[s[i]-'a']) continue;
		putchar(s[i]);
	}
	return 0;
}
