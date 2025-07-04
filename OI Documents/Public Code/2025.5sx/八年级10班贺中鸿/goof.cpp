#include<bits/stdc++.h>
#define wk(x) write(x),putchar(' ')
#define wh(x) write(x),putchar('\n')
#define ll long long
#define mod 998244353
#define N 200005
using namespace std;
int n,m,k,jk,ans,sum,num,cnt,tot;char a[N];
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
	char ch;
	int x;
}v[N];

bool cmp(P a,P b){return a.x<b.x;}

int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",a+1);read(n);
	m=strlen(a+1);
	for(int i=1;i<=m;i++)
	wis[a[i]]++,f[a[i]]=1,sum+=(wis[a[i]]==1);
	for(int i='a';i<='z';i++)
	++cnt,v[cnt].ch=i,v[cnt].x=wis[i];
	sort(1+v,1+cnt+v,cmp);
	for(int i=1;i<=cnt;i++){
		if(v[i].x+ans<=n)
		ans+=v[i].x,sum-=(v[i].x!=0),f[v[i].ch]=0;
		else break;
	}wh(sum);
	for(int i=1;i<=m;i++){
		if(f[a[i]]) putchar(a[i]);
	}return 0;
}
