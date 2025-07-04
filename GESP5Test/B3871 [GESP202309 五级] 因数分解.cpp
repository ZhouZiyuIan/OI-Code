#include<stdio.h>
#include<math.h>
long long n,cnt,first,pn;
main(){
	scanf("%lld",&n);
	pn=n;
	for(long long i=2;i<=sqrt(n);i++){
		if(n%i==0){
			cnt=0;
			while(n%i==0)n/=i,cnt++;
			if(!first)first=1;
			else printf(" * ");
			if(cnt!=1)printf("%lld^%lld",i,cnt);
			else printf("%lld",i);
		}
	}
	if(n!=1){
		if(n!=pn)printf(" * ");
		printf("%lld",n);
	}
}
