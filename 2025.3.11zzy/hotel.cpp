#include<stdio.h>
long long n,m,a;
main(){
	scanf("%lld%lld",&n,&m);
	if((n<<1)<=m)putchar('0');
	else printf("%lld",(n<<2)-(m<<1));
}
