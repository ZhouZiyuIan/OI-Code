#include<stdio.h>
int n,m,a[500001],seg[2000001];
void build(int k,int l,int r){
    if(l==r){
        seg[k]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(k<<1,l,mid);
    build(k<<1|1,mid+1,r);
    seg[k]=seg[k<<1]+seg[k<<1|1];
}
void modify(int k,int l,int r,int x,int val){
    if(l==x&&l==r){
        seg[k]+=val;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)modify(k<<1,l,mid,x,val);
    else modify(k<<1|1,mid+1,r,x,val);
    seg[k]=seg[k<<1]+seg[k<<1|1];
}
int getsum(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y)return seg[k];
    int mid=(l+r)>>1,ret=0;
    if(x<=mid)ret+=getsum(k<<1,l,mid,x,y);
    if(y>mid)ret+=getsum(k<<1|1,mid+1,r,x,y);
    return ret;
}
main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        if(a[0]==1)modify(1,1,n,a[1],a[2]);
        else printf("%d\n",getsum(1,1,n,a[1],a[2]));
    }
}