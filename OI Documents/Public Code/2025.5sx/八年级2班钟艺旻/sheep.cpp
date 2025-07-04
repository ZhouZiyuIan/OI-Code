#include<bits/stdc++.h>
using namespace std;
int n;
int a[2001];
int t;
bool ma[2001];
int b[2001];
int cnt;
long long sum=1;
int c[2001];
long long ans;
int main() {
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		if(a[i]==-1) {
			t++;
			c[t]=i;
		}
		ma[a[i]]=1;
	}
	if(n>12) {
		for(int i=1; i<=t; i++) {
			sum*=i;
			sum%=1000000007;
		}
		cout<<sum;
		return 0;
	}
	for(int i=1; i<=n; i++) {
		if(ma[i]==0) {
			cnt++;
			b[cnt]=i;
		}
	}
	while(next_permutation(b+1,b+cnt+1)) {
		bool p=0;
		for(int i=1; i<=cnt; i++) {
			if(b[i]==c[i]) {
				p=1;
				break;
			}
		}
		if(!p) {
			ans++;
			ans%=1000000007;
		}
	}
	cout<<ans;
	return 0;
}
