#include<bits/stdc++.h>
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
#define int long long
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

signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	read(n),read(m);
	for(int i=1;i<=n;i++){
		read(dis[i]);
		wis[i]=wis[i-1]+dis[i];
	}
	m%=wis[n];
	if(m==0){
		wh(n),wh(0);
	}else{
		for(int i=1;i<=n;i++){
			if(wis[i]<m) continue;
			wh(i),wh(wis[i]-m);
			return 0;
		}
	}
	return 0;
}
