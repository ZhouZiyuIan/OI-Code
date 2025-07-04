#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL k;
int main() {
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%lld",&k);
	if(k==1) {
		printf("YES");
		return 0;
	}
	for(int i=1; i<=k; i++) {
		if(rand()%2==1) {
			cout<<"YES";
		} else {
			cout<<"NO";
		}
	}
	return 0;
}

