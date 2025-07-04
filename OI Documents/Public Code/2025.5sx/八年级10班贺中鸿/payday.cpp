#include<bits/stdc++.h>
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
#define int long long
#define mod 998244353
#define N 300005
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

struct P{
	int x,y;
}v[N];

bool cmp(P a,P b){
	return (a.x<b.x)||(a.x==b.x&&a.y<b.y);
}

signed main(){
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	read(jk);while(jk--){
		read(n),read(m);
		for(int i=1;i<=n;i++){
			read(v[i].x),read(v[i].y);
			m-=v[i].x;
		}
		sort(1+v,1+n+v,cmp);
		int l=v[n/2+1].x,r=2000000005,mid;
		while(l<=r){
			mid=(l+r)>>1;int g=m,z=0;
			for(int i=n;i>=1;i--){
				if(v[i].y>=mid){
					if(v[i].x<mid&&g-(mid-v[i].x)>=0) g-=(mid-v[i].x),z++;
					else if(v[i].x>=mid) z++;
				}
			}
			if(z>n/2) l=mid+1;
			else r=mid-1;
		}wh(l-1);
	}return 0;
}
