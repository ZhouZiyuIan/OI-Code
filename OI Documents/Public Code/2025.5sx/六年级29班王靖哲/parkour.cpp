#include<bits/stdc++.h>
using namespace std;
int t,n,m,sx,sy;
int dy[5]={1,0,-1};
char a[10000][100];
/*void dfs(int x,int y){
	if(x>=m){
		printf("YES\n");
		return;
	}for(int i=0;i<2;i++){
		int xx=x+1,yy=y+dy[i];
		if(a[xx][yy]!='X'&&a[xx][yy]!='X'&&a[xx+2][yy]!='X'){
			for(int j=0;j<m;j++){
				for(int k=0;k<n;k++){
					if(k==n-1)a[j][k]='.';
					else if(a[j][k+1]=='X')a[j][k]=a[j][k+1];
				}
			}
			dfs(xx,yy);
			for(int j=m-1;j>=0;j++){
				for(int k=n-1;k>=0;k++){
					if(k==0)a[j][k]='.';
					else if(a[j][k-1]=='X')a[j][k]=a[j][k-1];
				}
			}
		}else{
			printf("NO");
			return;
		}
	}
}*/
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		for(int j=0;j<m;j++){
			for(int k=0;k<n;k++) scanf("%c",&a[j][k]);
		}printf("NO");
	}
}
