#include<bits/stdc++.h>
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
#define ll long long
#define mod 998244353
#define N 200005
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;char a[N/1000][N];
int head[N],dis[N],vis[N],wis[N],f[N];

void read(int &x){
	x=0;int y=1;
	char ch=getchar();
	while(!(ch>='0'&&ch<='9')){
		if(ch=='-') y=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch-'0');
		ch=getchar();
	}x=x*y;return;
}

void write(int x){
	if(x<0){x=-x;putchar('-');}
	if(x>=10) write(x/10);
	putchar('0'+x%10);
}

int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	read(jk);while(jk--){
		read(m),read(n);ans=0;num=0;
		for(int i=1;i<=n;i++) wis[i]=0;sum=1;
		for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='s') wis[i]=1;
			}
		}int bz=0;
		while(sum<=m&&!bz){sum++;
			for(int i=1;i<=n;i++)
				if(wis[i]&&a[i][sum]!='X') wis[i-1]=wis[i+1]=wis[i]=1;
				else wis[i]=0;
			for(int i=1;i<=n;i++){
				for(int j=min(m,sum);j<=min(m,sum+2)&&wis[i];j++){
					if(a[i][j]=='X') wis[i]=0; 
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=3;j<=m;j++){
					a[i][j-2]=a[i][j];
				}a[i][m]=a[i][m-1]='.';
			}
			for(int i=1;i<=n;i++){
				if(wis[i]) break;
				if(i==n) bz=1;
			}m-=2;
		}
		if(!bz) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
