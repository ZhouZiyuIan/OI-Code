#include<stdio.h>
unsigned long long f[61],n;
main(){
	scanf("%llu",&n);
	f[0]=1;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=n;++i)f[i]=f[i-3]+f[i-2]+f[i-1];
	printf("%llu",f[n]);
}
