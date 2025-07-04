#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=3e4+10;
int T,n,m,f[3][20],ans,g;
char ch[20][MAXN];
void clr(){
	ans=0,g=1;
	for(int i=1;i<=13;i++) f[0][i]=f[1][i]=0;
	memset(ch,0,sizeof(ch));
}
void work(){
	clr(),scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=m;i++) if(ch[i][1]=='s') f[0][i]=1;
	for(int i=2;i<=n;i++,g^=1){
		for(int j=1;j<=m;j++){
			int f1=i+(i-1)*2,f2=i+(i-2)*2;
			f[g][j]=f[g^1][j];
			if(ch[j-1][f2]!='X') f[g][j]=max(f[g^1][j-1],f[g][j]);
			if(ch[j+1][f2]!='X') f[g][j]=max(f[g^1][j+1],f[g][j]);
			if(ch[j][f1]=='X'||ch[j][f2]=='X') f[g][j]=0;
		} 
	}
	for(int i=1;i<=m;i++) ans=max(ans,f[g^1][i]);
	if(ans) puts("YES");
	else puts("NO");
}
signed main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&T);
	while(T--) work();
	return 0;
} 
