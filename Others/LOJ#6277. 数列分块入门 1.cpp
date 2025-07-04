#include<stdio.h>
typedef long long ll;
ll sum[40000001],n,m,op,x,y,k,a[10000001],tag[40000001];
inline void Add(ll k,ll l,ll r,ll v){
	tag[k]+=v;
	sum[k]+=(r-l+1)*v;
}
inline void pushdown(ll k,ll l,ll r,ll mid){
	if(tag[k]==0)return;
	Add(k<<1,l,mid,tag[k]);
	Add(k<<1|1,mid+1,r,tag[k]);
	tag[k]=0;
}
void build(ll k,ll l,ll r){
	if(l==r){
		sum[k]=a[l];
		return;
	}
	ll mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
inline ll quesum(ll goall,ll goalr,ll lcur,ll rcur,ll cur){
	if(goall<=lcur&&goalr>=rcur)return sum[cur];
	ll mid=(lcur+rcur)>>1,sum=0;
	pushdown(cur,lcur,rcur,mid);
	if(goall<=mid)sum+=quesum(goall,goalr,lcur,mid,cur<<1);
	if(goalr>mid)sum+=quesum(goall,goalr,mid+1,rcur,cur<<1|1);
	return sum;
}
inline void change(ll k,ll l,ll r,ll x,ll y,ll v){
	if(l>=x&&r<=y) {	
		Add(k,l,r,v);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(k,l,r,mid);
	if(x<=mid)change(k<<1,l,mid,x,y,v);
	if(y>mid)change(k<<1|1,mid+1,r,x,y,v);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
main(){
	scanf("%lld",&n);
	m=n;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	while(m--){
		scanf("%lld%lld%lld%lld",&op,&x,&y,&k);
		if(op)printf("%lld",quesum(y,y,1,n,1)),putchar('\n');
		else change(1,1,n,x,y,k);
	}
}
