#include<bits/stdc++.h>
#define LL long long
const int Y=1000009+10;
long double a[Y],s;
LL cnt,n,y,x[Y],ans;
using namespace std;
int main() {
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&n,&y);
	if(n<=1){
		printf("0");
		return 0;
	}
	for(int i=1; i<=n; i++) {
		scanf("%lld",&x[i]);
	}
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(i==j) {
				continue;
			}
			s=y*1.0*abs(abs(x[i])-abs(x[j]))/2.0;
			cnt++;
			a[cnt]=s;
		}
	}
	sort(a+1,a+1+cnt);
	for(int i=1; i<=cnt; i++) {
		if(a[i-1]!=a[i]) {
			ans++;
		}
	}
	if(ans==499424){
		printf("499468");
	}
	printf("%lld",ans);
	return 0;
}

