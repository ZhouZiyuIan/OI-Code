#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
using namespace std;
const int N=1e5+10;
struct node{
	double x;
	int w;
}a[N*2];
int n,cnt;
double w,u,v,st,tt,ans;
bool cmp(node x,node y)
{return x.x<y.x;}
int main()
{
	scanf("%d%lf%lf%lf%lf%lf",&n,&w,&u,&v,&st,&tt);
	for(int i=1;i<=n;i++){
		char op;int m;
		cin>>op>>m;
		for(int j=1;j<=m;j++){
			double l,p,sT,eT;
			scanf("%lf%lf",&l,&p);
			if(op=='E') sT=-p/u,eT=(l-p)/u;
			if(op=='W') sT=p/u,eT=(p+l)/u;
			if(sT>eT) swap(sT,eT);
			sT-=i*(w/v);eT-=(i-1)*(w/v);
			a[++cnt]=(node){sT,1};
			a[++cnt]=(node){eT,-1};
			printf("%lf %lf\n",sT,eT);
		}
	}
	sort(a+1,a+1+cnt,cmp);
	int now=0;
	ans=max(a[1].x-st,tt-a[cnt].x);
	printf("%.8lf %d\n",ans,now);
	for(int i=1;i<cnt;i++){
		now+=a[i].w;
		if(now==0){
				ans=max(ans,min(a[i+1].x,tt)-max(a[i].x,st));
		}
		
	}
	printf("%.8lf %d",ans,now);
}
