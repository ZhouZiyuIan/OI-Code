#include<stdio.h>
#include<string.h>
int T,n,m,f,lens,cx,cy,cnt,h,t,q[10000001][2],dy[3]={-1,0,1};
char s[11][10001];
void bfs(int x,int y){
	h=t=1;
	q[h][0]=x;
	q[h][1]=y;
	while(h<=t){
		int curx=q[h][0],cury=q[h][1];
		for(int i=0;i<3;i++){
			int newx=curx+dy[i],newy=cury+3;
			if(newx&&newx<=m && newy &&
			s[newx][newy]!='X' &&
			s[newx][cury+2]!='X' &&
			s[newx][cury+1]!='X' &&
			s[curx][cury+1]!='X'){
				t++;
				s[newx][newy]='X';
				q[t][0]=newx;
				q[t][1]=newy;
				if(newy==n){
					f=1; 
					return;
				} 
			}
		}
		h++;
	}
}
main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		f=cx=cy=0;
		for(int i=1;i<=m;i++){
			scanf("%s",s[i]+1);
			lens=strlen(s[i]+1);
			if(cx==0&&cy==0)for(int j=1;j<=lens;j++)if(s[i][j]=='s'){
				cx=i;
				cy=j;
				break;
			}
		}
		bfs(cx,cy);
		puts(f?"YES":"NO");
	}
}
