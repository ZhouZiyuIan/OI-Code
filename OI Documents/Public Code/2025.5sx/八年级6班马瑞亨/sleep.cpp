#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long n,t,a[N],sum;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
	}
	t=t%sum;
	int j=1;
	while(1) {
		if(t-a[j]>0) {
			t-=a[j];
		}
		else if(t-a[j]==0) {
			printf("%d\n0",j);
			break;
		}
		else {
			printf("%d\n%d",j,a[j]-t);
			break;
		}
		j++;
		if(j>n) j=1;
	}
	return 0;
}
