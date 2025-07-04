#include<bits/stdc++.h>
using namespace std;
int n,tmp;
long long t,a[100005],sum = 0;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%lld",&n,&t);
	for(int i = 1;i <= n;i++) {
		scanf("%lld",&a[i]);
		sum += a[i];
	}
	t %= sum;
	tmp = 1;
	while(t > a[tmp]) {
		t -= a[tmp];
		tmp++;
		if(tmp > n) {
			tmp = 1;
		}
	}
	t = a[tmp] - t;
	printf("%d\n%d",tmp,t);
}  
