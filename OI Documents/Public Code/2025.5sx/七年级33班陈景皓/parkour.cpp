#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=2e6+5,X=1e4+5;
int T,n,m;
bool t;
char a[15][X];
int b[15][X];
void dg(int x,int y){
	y++;
	if(y>m){
		t=1;
		return;
	}
	if(a[x][y]=='X'||b[x][y])return;
	b[x][y]=1;
	if(t)return;
	
	for(rint i=-1;i<=1;++i){
		int xx=x+i;
		if(t)return;
		if(xx>0&&xx<=n&&a[xx][y]!='X'){
			if(y+1<=m&&a[xx][y+1]!='X'){
				if(y+2<=m&&a[xx][y+2]!='X'){
					dg(xx,y+2);
				}else if(y+2>m){
					dg(xx,y+2);
				}
			}else if(y+1>m){
				dg(xx,y+2);
			}
		}
	}
}
signed main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--){
		rint x,y;
		t=0;
		cin>>n>>m;
		swap(n,m);
		for(rint i=1;i<=n;++i){
			for(rint j=1;j<=m;++j){
				b[i][j]=0;
			}
		}
		for(rint i=1;i<=n;++i){
			for(rint j=1;j<=m;++j){
				cin>>a[i][j];
				if(a[i][j]=='s')x=i,y=j;
			}
		}
		dg(x,y);
		if(t)cout<<"YES";
		else cout<<"NO";
		cout<<'\n';
	}
	return 0;
}



