#include<stdio.h>
typedef long long ll;
ll n,a[11],b=1;
ll gcd(ll a,ll b){return b==0?a:gcd(b,a%b);}
main(){
	scanf("%lld",&n);
	for(ll i=0;i<n;i++)scanf("%lld",&a[i]);
	for(ll i=0;i<n;i++)b=(b*a[i])/gcd(b,a[i]);
	printf("%lld",b);
}
