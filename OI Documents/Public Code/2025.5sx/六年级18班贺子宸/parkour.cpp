#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
int t,n,m,x,y,xx;
int dx[3]={-1,0,1};
char s[10005][15];
bool vis[10005][15];
struct node{
	int x,y;
};
bool solve(){
	memset(vis,0,sizeof vis);
	queue<node>q;
	q.push({x,1});
	while(q.size()){
		x=q.front().x;
		y=q.front().y+1;
		q.pop();
		if(y==m)return 1;
		if(s[x][y]=='X')
			return 0;
		if(vis[x][y])
			continue;
		for(int i=0;i<3;i++){
			xx=x+dx[i];
			if(xx&&xx<=n&&s[xx][y+1]!='X'&&s[xx][y+2]!='X'&&!vis[xx][y]){
				if(y+2>=m)return 1;
				vis[xx][y]=1;
				q.push({xx,y+2});
			}
		}
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		swap(n,m);
		for(int i=1;i<=n;i++)
			cin>>s[i]+1;
		for(int i=1;i<=n;i++){
			if(s[i][1]=='s'){
				x=i;
				break;
			}
		}
		if(solve())
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
