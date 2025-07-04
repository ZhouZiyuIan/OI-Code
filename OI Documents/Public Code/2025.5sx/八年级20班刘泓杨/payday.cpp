#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+10,INF=1e9+7;
int T,n,m,ans,sum;
struct node{
	int l,r;
}a[MAXN];
int check(int x){
	int g=0,cnt1=0,w=0;
	for(int i=1;i<=n;i++) if(a[i].r<x) ++cnt1,w+=a[i].l;
	for(int i=1;i<=n;i++){
		if(a[i].l<=x&&a[i].r>=x){
			if(g+cnt1>=n/2) w+=x;
			else ++g,w+=a[i].l;
		} 
		if(a[i].l>x) w+=a[i].l;
	}
	if(w>sum||cnt1>n/2) return 0;
	return 1;
}
int cmp(node x,node y){
	return x.l<y.l;
}
void work(){
	scanf("%lld%lld",&n,&sum);
	int L=INF,R=sum;
	for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].l,&a[i].r),L=min(L,a[i].l);
	sort(a+1,a+1+n,cmp);
	while(L<=R){
		int mid=(L+R)>>1;
		if(check(mid)) L=mid+1,ans=mid;
		else R=mid-1;
	}
	printf("%lld\n",ans);
}
signed main(){
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	scanf("%lld",&T);
	while(T--) work();
	return 0;
} 
