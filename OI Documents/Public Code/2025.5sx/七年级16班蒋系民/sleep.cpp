#include<stdio.h>
#define ll long long
const int N=1e5+5;
ll n,t,a[N];
void how(int x) {
	for(ll i=1; i<=n; i++) {
		if(x<=a[i]) {
			printf("%lld\n%lld",i,a[i]-x);
			return;
		}
	}
	how(x-a[n]);
}
int main(void) {
	scanf("%lld %lld",&n,&t);
	for(ll i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		a[i]+=a[i-1];
		if(t<=a[i]) {
			printf("%lld\n%lld",i,a[i]-t);
			return 0;
		}
	}
	how(t);
	return 0;
}
