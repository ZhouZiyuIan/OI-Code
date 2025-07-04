#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,x[N],zhq,mo,qian[N],t;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	scanf("%d%lld",&n,&t);
	for(int i=1; i<=n; i++) {
		scanf("%d",&x[i]);
		zhq+=x[i];
	}
	for(int i=1; i<=n; i++) {
		qian[i]=x[i]+qian[i-1];
	}
	mo=t%zhq;
	for(int i=1; i<=n; i++) {
		if(mo>qian[i-1]&&mo<=qian[i]) {
			printf("%d\n%d",i,qian[i]-mo);
			return 0;
		}
	}
	return 0;
}

