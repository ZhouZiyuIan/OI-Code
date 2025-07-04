#include<stdio.h>
long long T,n,k,t,a,b;
long long gcd(long long a,long long b){return b?gcd(b,a%b):a;}
long long lcm(long long a,long long b){return a*b/gcd(a,b);}
main(){
	scanf("%lld",&T);
	while(T--){
		scanf("%lld%lld",&n,&k);
		a=n/k;
		b=a+1;
		t=n%k;
		if(t==0)printf("%lld\n",(~(-k))?((n/k)<<1):n);
		else if(~(-t))printf("%lld\n",k-t==1?lcm(a,b<<1):(a*b<<1));
		else printf("%lld\n",k-t==1?a*b:lcm(a<<1,b));
	}
}
