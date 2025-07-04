#include<stdio.h>
int n,m,type,l,r,tmp;
unsigned int v,x0,seed,a[100001];
unsigned int getnum()
{
		x0=(x0<<3)^x0;
		x0=((x0>>5)+seed)^x0;
		return x0;
}
unsigned max(unsigned a,unsigned b){return a>b?a:b;}
int main()
{
	freopen("train.in","r",stdin);
    freopen("train.out","w",stdout);
	scanf("%d%d%d",&n,&m,&type);
	for(int i=1;i<=n;i++)scanf("%u",&a[i]);
	scanf("%u%u",&x0,&seed);
	for(int i=1;i<=m;i++)
	{
		l=getnum()%n+1;
		r=getnum()%n+1;
		v=getnum();
		if(l>r)
		{
			tmp=l;
			l=r;
			r=tmp;
		}
		if(type==1)l=1;
 		for(int j=l;j<=r;j++)a[j]=max(a[j],v);
 	}
	for(int i=1;i<=n;i++)printf("%u ",a[i]);
}