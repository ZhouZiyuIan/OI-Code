#include<bits/stdc++.h>
using namespace std;
int n,a[2005],vis[2005],sum,cnt;
long long ans = 1;
int main() {
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i = 1;i <= n;i++) {
		cin>>a[i];
		vis[a[i]] = 1;
		if(a[i] != -1) sum++;
	} 
	for(int i = 1;i <= n;i++) {
		if(a[i] == -1) {
			int tmp = sum;
			if(vis[i]) {
				tmp--;
			}
			ans *= tmp;
			ans %= 1000000007;
			sum--;
		}
	}
	cout<<ans;
}
