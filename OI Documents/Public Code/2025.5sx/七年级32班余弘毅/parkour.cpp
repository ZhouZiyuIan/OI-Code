#include<bits/stdc++.h>
#define int long long
using namespace std;
int sx,sy,n,m,T;
char maz[15][30005];
int dx[5]={0,0,-1,1};
int dy[5]={0,1,0,0};
struct Node{int x,y,t;};
map<int,map<int,map<int,int> > > vis; 
inline bool check(int x,int y,int t){return (x<=n&&x>=1&&y<=m&&y>=1&&maz[x][y+2*t]!='X');}
inline void solve(){
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>maz[i]+1;
		for(int j=1;j<=m;j++){
			if(maz[i][j]=='s') sx=i,sy=j;
		}
	}
	queue<Node>q;q.push({sx,sy,0});vis.clear();
	while(!q.empty()){
		Node u=q.front();q.pop();
		if(vis[u.x][u.y][u.t]) continue;
		vis[u.x][u.y][u.t]=1;
		for(int i=0;i<4;i++){
			int xx=u.x+dx[i],yy=u.y+dy[i];
			if(check(xx,yy,u.t)&&check(xx,yy,u.t+1)){
				if(yy==m){cout<<"YES\n";return;}
				q.push({xx,yy,u.t+1});
			}
		}
	}
	cout<<"NO\n";
}
signed main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>T;
	while(T--) solve(); 
	return 0;
} 
