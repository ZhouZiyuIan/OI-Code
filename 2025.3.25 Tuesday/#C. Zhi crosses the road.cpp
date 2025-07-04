#include<stdio.h>
#include<stdlib.h>
#include<utility>
using namespace std;
pair<double,int>a[200001];
int n,m,l,p,now,cnt;
double w,u,v,sp,ep,ans,t1,t2;
char drc;
double max(double a,double b){return a>b?a:b;}
double min(double a,double b){return a<b?a:b;}
int cmp(const void*a,const void*b){return (*(pair<double,int>*)a<*(pair<double,int>*)b)?-1:1;}
main(){
	scanf("%d%lf%lf%lf%lf%lf",&n,&w,&u,&v,&t1,&t2);
	for(int i=1;i<=n;i++){
		scanf("\n%c%d",&drc,&m);
		for(int j=0;j<m;j++){
			scanf("%d%d",&l,&p);
			if(drc=='E'){
				sp=-p/u;
				ep=(l-p)/u;
			}
			else{
				sp=p/u;
				ep=(l+p)/u;
			}
			if(sp>ep)swap(sp,ep);
			sp-=i*(w/v);
			ep-=(i-1)*(w/v);
			a[cnt++]={sp,1};
			a[cnt++]={ep,-1};
		}
	}
	qsort(a,cnt,sizeof(pair<double,int>),cmp);
	ans=max(a[0].first-t1,t2-a[cnt-1].first);
	for(int i=0;i<cnt-1;i++){
		now+=a[i].second;
		if(now==0)ans=max(ans,min(a[i+1].first,t2)-max(a[i].first,t1));
	}
	printf("%lf",ans);
}
