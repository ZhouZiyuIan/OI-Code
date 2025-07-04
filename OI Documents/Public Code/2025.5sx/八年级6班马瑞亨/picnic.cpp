#include<bits/stdc++.h>
using namespace std;
const int N=1e3+5;
long long n,y,x[N];
long long a[1000005],cnt,ans;
int main() {
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++) {
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n-1;i++) {
		for(int j=i+1;j<=n;j++) {
			a[++cnt]=x[j]-x[i];
		}
	}
	sort(a+1,a+cnt+1);
	a[0]=1e10;
	for(int i=1;i<=cnt;i++) {
		if(a[i]!=a[i-1]) {
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
