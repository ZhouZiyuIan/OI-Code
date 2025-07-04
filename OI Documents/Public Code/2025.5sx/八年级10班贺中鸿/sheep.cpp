#include<bits/stdc++.h>
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
#define ll long long
#define mod 998244353
#define N 200005
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;
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

void dfs(int x){
	if(x>n){
		ans++;
		return;
	}
	if(dis[x]!=-1) dfs(x+1);
	else{
		for(int i=1;i<=n;i++){
			if(!f[i]&&i!=x){
				f[i]=1;dis[x]=i;
				dfs(x+1);
				f[i]=0;dis[x]=-1;
			}
		}
	}
}

int main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	read(n);
	for(int i=1;i<=n;i++){
		read(dis[i]);
		if(dis[i]!=-1) f[dis[i]]=1;
	}dfs(1);wh(ans);
	return 0;
}
