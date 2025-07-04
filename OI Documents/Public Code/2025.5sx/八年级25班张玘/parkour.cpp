#include<cstdio>
using namespace std;
const int maxn=1e4+1e3;
int t,n,m;
char s[20][maxn];
void solve()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
			if(s[j][i-1]=='s'&&s[j][i]=='.')s[j][i]='s';
		if(i%3==2)
			for(int j=1;j<=n;j++)
				if(s[j][i]=='s')
				{
					if(s[j-1][i]=='.')s[j-1][i]='s';
					if(s[j+1][i]=='.')s[j+1][i]='s';
				}
	}
	for(int i=1;i<=n;i++)
		if(s[i][m]=='s')
		{
			printf("Yes\n");
			return;
		}
	printf("No\n");
}
int main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	while(t--)solve();
	return 0;
}
