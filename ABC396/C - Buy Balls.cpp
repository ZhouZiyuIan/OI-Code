#include<stdio.h>
#include<stdlib.h>
long long n,m,b[200001],w[200001],cur,stt;
long long min(long long a,long long b){return a<b?a:b;}
int cmp(const void*a,const void*b){return (*(long long*)b-*(long long*)a);}
main(){
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&b[i]);
	for(int i=0;i<m;i++)scanf("%lld",&w[i]);
	qsort(b,n,sizeof(long long),cmp);
	qsort(w,m,sizeof(long long),cmp);
	stt=min(n,m);
	for(int i=0;i<min(n,m);i++){
		if(b[i]+w[i]<=0||w[i]<=0){
			stt=i;
			break;
		}
		cur+=b[i]+w[i];
	}
	for(int i=stt;i<n;i++)if(b[i]>0)cur+=b[i];
	printf("%lld",cur);
}