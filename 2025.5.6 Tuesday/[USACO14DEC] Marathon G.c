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
template<typename type>
T abs(int a){return a<0?-a:a;}
int px[100001],py[100001],n,q,dis[400001],delta[400001],I,X,Y;
char op;
int mdis(int a,int b){return abs(px[a]-px[b])+abs(py[a]-py[b]);}
void build(int k,int l,int r){
	if(l==r){
		delta[k]=l<n-1?dis(l,l+1)+dis(l+1,l+2):0;
		dis[k]=l<n?dis(l,l+1):0;
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
main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d%d",&px[i],&py[i]);
	build(1,1,n);
	while(q--){
		scanf("\n%c %lld %lld",&op,&I,&X);
		if(op=='U'){
			//update
		}
		else{
			printf("%d\n",query_dis(1,1,n,I,X)-query_delta(1,1,n,I,X));
		}
	}
}