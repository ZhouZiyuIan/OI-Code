#include<stdio.h>
#include<stdlib.h>
int n,h;
long long tt,mx=-1;
long long min1(long long a,long long b){return a<b?a:b;}
typedef struct{
	int t,w,p;
}cow;
cow c[21];
int cmp(const void*a,const void*b){
	cow*ia=(cow*)a;
	cow*ib=(cow*)b;
	if(ia->w+ia->p<ib->w+ib->p)return 1;
	return -1;
}
void dfs(int x,long long curh,long long curp){
	if(curh>=h){
		mx<curp?mx=curp:0;
		return;
	}
	if(x==n)return;
	if(curp>=c[x].w)dfs(x+1,curh+c[x].t,min1(curp-c[x].w,c[x].p));
	dfs(x+1,curh,curp);
}
main(){
	scanf("%d%d",&n,&h);
	for(int i=0;i<n;i++){
		scanf("%d%d%d",&c[i].t,&c[i].w,&c[i].p);
		tt+=c[i].t;
	}
	qsort(c,n,sizeof(cow),cmp);
	dfs(0,0,9223372036854775807ll);
	if(tt<h||mx==-1){
		puts("Mark is too tall");
		return 0;
	}
	printf("%lld",mx);
}