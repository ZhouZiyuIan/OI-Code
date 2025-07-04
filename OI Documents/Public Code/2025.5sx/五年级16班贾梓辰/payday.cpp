#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct st {
	LL l,r;
} x[100001];
bool cmp(st j,st k) {
	if(j.l>k.l) {
		return 0;
	}
	return 1;
}
long long m,n,s;
int main() {
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	scanf("%lld",&m);
	for(int x=1; x<=m; x++) {
		scanf("%lld%lld",&n,&s);
		for(int i=1; i<=n; i++) {
			scanf("%lld%lld",&x[i].l,&x[i].r);
		}
		sort(x+1,x+1+n,cmp);
		for(int i=1; i<=n/2; i++) {
			s-=x[i].l;
		}
		LL z=x[n/2].l;
		//x[n/2+1].l;//最小值
		//x[n].最大值
		cout<<(x[n/2+1]+x[n])/2;
	}
	return 0;
}

