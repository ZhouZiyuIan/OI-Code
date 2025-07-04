#include<bits/stdc++.h>
using namespace std;
long long t,n,m;
char s[15][10005];
bool dp[10005][15];
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
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	read(t);
	while(t--)
	{
		read(n);read(m);
		for(int i=1;i<=m;i++)
		{
			scanf("%s",s[i]+1);
			if(s[i][1]=='s') dp[1][i]=1;
			s[i][n+1]=0;
		}
		for(int i=2;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(s[j][min(n+1,1ll*i+(i-1)*2)]=='X'||s[j][min(n+1,1ll*i+(i-2)*2)]=='X') continue;
				dp[i][j]=((s[j-1][min(n+1,1ll*i+(i-2)*2)]!='X')*dp[i-1][j-1])|((s[j][min(n+1,1ll*i+(i-2)*2)]!='X')*dp[i-1][j])|((s[j+1][min(n+1,1ll*i+(i-2)*2)]!='X')*dp[i-1][j+1]);
			}
		}
		bool ans=0;
		for(int j=1;j<=m;j++) ans|=dp[n][j];
		if(ans) printf("YES\n");
		else printf("NO\n");
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) dp[i][j]=0;
	}
	return 0;
}
