#include<bits/stdc++.h>
using namespace std;
void fre()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
}
int n,m,t;
map<int,map<int,map<int,char> > > a;
bool dfs(int x,int y)
{
	if(x<1||x>m) return false;
	if(y==n) return true;
	else
	{
		if(a[t][x][y+1]=='X') return false;
		y++;
		bool k1=false,k2=false,k3=false;
		if(a[t][x+1][y]!='X'&&a[t][x+1][y+1]!='X'&&a[t][x+1][y+2]!='X') k1=dfs(x+1,y+2);
		if(a[t][x-1][y]!='X'&&a[t][x-1][y+1]!='X'&&a[t][x-1][y+2]!='X') k2=dfs(x-1,y+2);
		if(a[t][x][y]!='X'&&a[t][x][y+1]!='X'&&a[t][x][y+2]!='X') k3=dfs(x,y+2);
		return (k1||k2||k3);
	}
}
int main()
{
	fre();
	for(cin>>t;t;t--,puts(""))
	{
		cin>>n>>m;int x=0,y=0;
		for(int i=1;i<=m;i++)
		{
			string b;cin>>b;
			for(int j=1;j<=n;j++)
			{
				a[t][i][j]=b[j-1];
				if(b[j-1]=='s') x=i,y=j;
			}
		}
		if(dfs(x,y)) cout<<"YES";
		else cout<<"NO";
	}
	return 0;
}
