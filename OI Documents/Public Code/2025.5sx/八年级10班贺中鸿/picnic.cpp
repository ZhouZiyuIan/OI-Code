#include<bits/stdc++.h>
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
#define int long long
#define mod 998244353
#define N 200005
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;
int head[N],dis[N],vis[N],wis[N],f[N];
map<int,int> kis;

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

int z(int x){return x>=0?x:-x;}

signed main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++) read(dis[i]);
	sort(1+dis,1+dis+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(kis[z(dis[i]-dis[j])]) continue;
			kis[z(dis[i]-dis[j])]=1;ans++;
		}
	}wh(ans);
	return 0;
}
