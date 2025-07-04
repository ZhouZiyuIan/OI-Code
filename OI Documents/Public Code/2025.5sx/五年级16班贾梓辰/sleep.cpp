#include<bits/stdc++.h>
#define LL long long
const int Y=100009;
LL n,t,a[Y],m;
unsigned long long sum;
using namespace std;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%lld%lld",&n,&t);
	for(LL i=1; i<=n; i++) {
		scanf("%lld",&a[i]);
		sum+=a[i];
	}
	m=t%sum;
	if(m==0) {
		printf("%lld\n0",n);
		return 0;
	}
	for(LL i=1; i<=n; i++) {
		m-=a[i];
		if(m<=0) {
			printf("%lld\n%lld",i,abs(m));
			break;
		}
	}
	return 0;
}
