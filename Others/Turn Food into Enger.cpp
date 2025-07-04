#include<stdio.h>
int n,m,k,a[201],b[201],c[201],mx,tmp;
main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<m;i++)scanf("%d",&b[i]);
	for(int i=0;i<k;i++)scanf("%d",&c[i]);
	for(int i=0;i<n;i++)for(int j=0;j<m;j++)for(int f=0;f<k;f++){
		tmp=(a[i]*b[j])%c[f];
		mx<tmp?mx=tmp:0;
	}
	printf("%d",mx);
}
