#include<stdio.h>
template<typename type>
void read(type &x){
	x=0;
	bool f=0;
	char a=getchar();
	while(!(a>='0'&&a<='9')){
		if(a=='-')f=1;
		a=getchar();
	}
	while(a>='0'&&a<='9'){
		x=x*10+(a-'0');
		a=getchar();
	}
	f?x=-x:0;
}
template<typename type>
void write(type x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+'0');
}
char write(const char ch){return putchar(ch);}
char read(char &ch){return ch=getchar();}
double read(double &kk){return scanf("%lf",&kk);}
template<typename type,typename ...T>
void read(type &x,T&...y){read(x),read(y...);}
template<typename T>
T max(T a,T b){return a<b?b:a;}
template<typename T>
T min(T a,T b){return a>b?b:a;}
template<typename T>
T abs(T a){return a<0?-a:a;}
int px[1000001],py[1000001],n,q,dis[4000001],delta[4000001],I,X,Y;
char op[2];
int mdis(int a,int b){return abs(px[a]-px[b])+abs(py[a]-py[b]);}
void build(int k,int l,int r){
	if(l==r){
		delta[k]=l<n-1?mdis(l,l+1)+mdis(l+1,l+2)-mdis(l,l+2):0;
		dis[k]=l<n?mdis(l,l+1):0;
		return;
	}
	int mid=(l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	delta[k]=max(delta[k<<1],delta[k<<1|1]);
	dis[k]=dis[k<<1]+dis[k<<1|1];
}
int query_dis(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y)return dis[k];
    int mid=(l+r)>>1,ret=0;
    if(x<=mid)ret+=query_dis(k<<1,l,mid,x,y);
    if(y>mid)ret+=query_dis(k<<1|1,mid+1,r,x,y);
    return ret;
}
int query_delta(int k,int l,int r,int x,int y){
    if(x<=l&&r<=y)return delta[k];
    int mid=(l+r)>>1,ret=-1;
    if(x<=mid)ret=max(query_delta(k<<1,l,mid,x,y),ret);
    if(y>mid)ret=max(query_delta(k<<1|1,mid+1,r,x,y),ret);
    return ret;
}
void modify_dis(int k,int l,int r,int x){
    if(l>x||r<x)return;
    if(l==x&&l==r){
        dis[k]=mdis(l,l+1);
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)modify_dis(k<<1,l,mid,x);
    else modify_dis(k<<1|1,mid+1,r,x);
    dis[k]=dis[k<<1]+dis[k<<1|1];
}
void modify_delta(int k,int l,int r,int x){
	if(l>x||r<x)return;
    if(x<=l&&r==x){
        if(l>=1&&l<n-1)delta[k]=mdis(l,l+1)+mdis(l+1,l+2)-mdis(l,l+2);
        else delta[k]=0;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid)modify_delta(k<<1,l,mid,x);
    else modify_delta(k<<1|1,mid+1,r,x);
    delta[k]=max(delta[k<<1],delta[k<<1|1]);
}
int main(){
	read(n,q);
	for(int i=1;i<=n;i++)read(px[i],py[i]);
	build(1,1,n);
	while(q--){
		scanf("%s",op);
		read(I,X);
		if(op[0]=='U'){
			read(Y);
			px[I]=X;
			py[I]=Y;
			modify_dis(1,1,n,I-1);
			modify_dis(1,1,n,I);
			modify_delta(1,1,n,I-2);
			modify_delta(1,1,n,I-1);
			modify_delta(1,1,n,I);
		}
		else write(query_dis(1,1,n,I,X-1)-query_delta(1,1,n,I,X-2)),putchar('\n');
	}
}