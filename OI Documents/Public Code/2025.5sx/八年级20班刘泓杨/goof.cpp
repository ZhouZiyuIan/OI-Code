#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,m,sum,a[MAXN],flg,vis[1234],k[1234];
char ch[MAXN];
struct node{
	int w,id;
}f[MAXN];
int cmp(node x,node y){
	return x.w<y.w;
}
signed main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s%d",ch+1,&m),n=strlen(ch+1);
	for(int i=1;i<=n;i++) ++k[ch[i]],sum+=(k[ch[i]]==1);
	for(int i='a';i<='z';i++) if(k[i]) f[++flg]={k[i],i};
	sort(f+1,f+1+flg,cmp);
	for(int i=1;i<=flg;i++){
		if(m<f[i].w) break;
		vis[f[i].id]=1,sum--,m-=f[i].w;
	}
	printf("%d\n",sum);
	for(int i=1;i<=n;i++) if(!vis[ch[i]]) printf("%c",ch[i]);
	return 0;
} 
