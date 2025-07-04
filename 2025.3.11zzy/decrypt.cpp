#include<stdio.h>
int max(int a,int b){return a>b?a:b;}
int fstorsum(int l,int r){
	while(r>l)l|=(l+1);
	return l;
}
int t,n,m,a;
main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		printf("%d\n",fstorsum(max(0,n-m),n+m));
	}
}
