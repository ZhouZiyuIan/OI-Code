#include<stdio.h>
int n,m,type,a[10000001],l,r,tmp;
unsigned int v,x0,seed,seg[40000001],tag[40000001],smn[40000001];
inline unsigned int getnum()
{
		x0=(x0<<3)^x0;
		x0=((x0>>5)+seed)^x0;
		return x0;
}
inline unsigned int max(unsigned int a,unsigned int b){return a>b?a:b;}
inline unsigned int min(unsigned int a,unsigned int b){return a<b?a:b;}
inline void addtag(int k,int l,int r,unsigned int v){tag[k]=v;seg[k]=max(v,seg[k]);}
inline void build(int k,int l,int r){
	if(l==r){
		seg[k]=smn[k]=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	seg[k]=max(seg[k<<1],seg[k<<1|1]);
	smn[k]=min(smn[k<<1],smn[k<<1|1]);
}
inline void pushdown(int k,int l,int r,unsigned int mid){
	if(tag[k]==0)return;
	addtag(k<<1,l,mid,tag[k]);
	addtag(k<<1|1,mid+1,r,tag[k]);
	tag[k]=0;
}
inline void modify(int k,int l,int r,int x,int y,unsigned int v){
	if(smn[k]>v)return;
	if(l>=x&&r<=y){
		addtag(k,l,r,v);
		return;
	}
	int mid=(l+r)>>1;
	pushdown(k,l,r,mid);
	if(x<=mid)modify(k<<1,l,mid,x,y,v);
	if(y>mid)modify(k<<1|1,mid+1,r,x,y,v);
	seg[k]=max(seg[k<<1],seg[k<<1|1]);
	smn[k]=min(smn[k<<1],smn[k<<1|1]);
}
inline unsigned int query(int goall,int goalr,int lcur,int rcur,int cur){
	if(goall<=lcur&&goalr>=rcur)return seg[cur];
	int mid=(lcur+rcur)>>1,lval=0,rval=0;
	pushdown(cur,lcur,rcur,mid);
	if(goall<=mid)lval=query(goall,goalr,lcur,mid,cur<<1);
	if(goalr>mid)rval=query(goall,goalr,mid+1,rcur,cur<<1|1);
	return max(lval,rval);
}
int main()
{
	// freopen("train.in","r",stdin);
    // freopen("train.out","w",stdout);
	scanf("%d%d%d",&n,&m,&type);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	build(1,1,n);
	scanf("%u%u",&x0,&seed);
	for(int i=1;i<=m;i++)
	{
		l=getnum()%n+1;
		r=getnum()%n+1;
		v=getnum();
		if(l>r){
			tmp=l;
			l=r;
			r=tmp;
		}
		if(type==1)l=1;
		modify(1,1,n,l,r,v);
 	}
	for(int i=1;i<=n;i++)printf("%u ",query(i,i,1,n,1));
}