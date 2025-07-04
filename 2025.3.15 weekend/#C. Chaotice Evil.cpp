#include<stdio.h>
#include<stdlib.h>
int n,m,a[1000002],d[500010];
int cmp(const void*a,const void*b){return(*(int*)a-*(int*)b);}
main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    if(n&(n-1))a[++n]=0;
	qsort(a,n+1,sizeof(int),cmp);
	for(int i=1;i<=n/2;i++)d[i]=a[2*i]-a[2*i-1];
}