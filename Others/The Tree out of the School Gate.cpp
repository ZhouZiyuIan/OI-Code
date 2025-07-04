#include<stdio.h>
#include<stdio.h>
typedef long long ll;
ll sum[4000001],n,m,op,x,y,k,tag[4000001];
void Add(ll k,ll l,ll r,ll v){
	tag[k]+=v;
	sum[k]+=(r-l+1)*v;
}
void pushdown(ll k,ll l,ll r,ll mid){
	if(tag[k]==0)return;
	Add(k<<1,l,mid,tag[k]);
	Add(k<<1|1,mid+1,r,tag[k]);
	tag[k]=0;
}
void build(ll k,ll l,ll r){
	if(l==r){
		sum[k]=0;
		return;
	}
	ll mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
ll query_sum(ll goall,ll goalr,ll lcur,ll rcur,ll cur){
	if(goall<=lcur&&goalr>=rcur)return sum[cur];
	ll mid=(lcur+rcur)>>1,sum=0;
	pushdown(cur,lcur,rcur,mid);
	if(goall<=mid)sum+=query_sum(goall,goalr,lcur,mid,cur<<1);
	if(goalr>mid)sum+=query_sum(goall,goalr,mid+1,rcur,cur<<1|1);
	return sum;
}
void Modify(ll k,ll l,ll r,ll x,ll y,ll v){
	if(l>=x&&r<=y) {	
		Add(k,l,r,v);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(k,l,r,mid);
	if(x<=mid)Modify(k<<1,l,mid,x,y,v);
	if(y>mid)Modify(k<<1|1,mid+1,r,x,y,v);
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
main(){
	scanf("%lld%lld",&n,&m);
	build(1,1,n);
	while(m--){
		scanf("%lld%lld%lld",&op,&x,&y);
		if(op==1)Modify(1,1,n,x,y,1);
		else printf("%lld %lld\n",query_sum(1,x,1,n,1),query_sum(1,y,1,n,1));
	}
}