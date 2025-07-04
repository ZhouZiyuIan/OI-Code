#include<bits/stdc++.h>
#define endl '\n'
#define int int
#define rep(i,a,b) for(register int i(a);i<=b;++i)
#define ref(i,a,b) for(register int i(a);i>=b;--i)
#define rek(i,a,b) for(register int i(a);i<b;++i)
#define Tie ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
using namespace std;
int T,n,m,sx,sy;
int a[15][10005];
int vis[15][10005];
char c;
struct Node{int x,y,t;};
signed main()
{
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	Tie,cin>>T;
	while(T--)
	{
		memset(vis,0,sizeof vis);
		cin>>n>>m,swap(n,m);
		rep(i,1,n)
		{
			rep(j,1,m)
			{
				cin>>c,a[i][j]=vis[i][j]=0;
				if(c=='X') a[i][j]=1;
				if(c=='s') sx=i,sy=j;
			}
		}
		queue<Node> q;
		q.push({sx,sy,0});
		int flag=0;
		while(!q.empty())	
		{
			int x=q.front().x,y=q.front().y,t=q.front().t;q.pop();
			if(y+t*2<m&&a[x][y+t*2]||vis[x][y]){continue;}
			if(y==m){flag=1;break;}
			vis[x][y]=1;
//			cout<<x<<" "<<y<<" "<<t<<endl;
			rep(i,-1,1) if(x+i>0&&x+i<=n&&a[x+i][y+1+2*t]==0&&a[x][y+1+2*t]==0) q.push({x+i,y+1,t+1});
		}
		if(flag) cout<<"YES\n";
		else cout<<"NO\n"; 
	}
}
