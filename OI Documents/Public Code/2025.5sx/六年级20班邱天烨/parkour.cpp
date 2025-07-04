#include<bits/stdc++.h>
using namespace std;
int n,m,t,cnt,sx,sy;
char s[11][10010];
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	cin>>t;
	while(t--){
		memset(s,'\0',sizeof(s));
		cnt=0,sx=-1,sy=-1;
		cin>>n>>m;
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				cin>>s[i][j];
				if(s[i][j]=='s')s[i][j]='.',sx=i,sy=j;
			}
		}
		if(s[sx][sy+1]=='X'){
			cout<<"NO\n";
			continue;
		}
		if(sy>n){
			cout<<"YES\n";
			continue;
		}
		bool f=true;
		int fx[2],fy[2];
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(s[i][j]!='X' or s[i][j+1]!='.')continue;
				bool l=0;
				int dx[6]={1,0,-1,1,0,-1};
				int dy[6]={1,1,1,2,2,2};
				for(int d=0;d<6;d++){
					int xx=i+dx[d],yy=j+dy[d];
					if(s[xx][yy]=='X' and (s[xx][yy+1]=='.' or s[xx][yy-1]=='.')){
						f=false;
						fx[0]=i,fx[1]=xx;
						fy[0]=j,fy[1]=yy;
						break;
					}
				}
				if(!f)break;
			}
			if(!f)break;
		}
		cout<<(f?"YES\n":"NO\n");
	}
	return 0;
}
/*
2
16 3
...XXXXX........
s.XXX......XXXXX
........XXXXX...
16 3
...XXXXX........
s.XXX....XXXXX..
.......XXXXX....
*/
