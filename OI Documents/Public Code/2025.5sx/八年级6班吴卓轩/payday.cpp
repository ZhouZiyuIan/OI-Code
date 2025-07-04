#include<bits/stdc++.h>

using namespace std;
#define int long long

int T,n,s,l[200005],r[200005],mx,num[200005];

void dfs(int x,int sum) {
	if(x>n) {
		if(sum>s) return;
		sort(num+1,num+n+1);
		mx=max(mx,num[n/2+1]);
		cout<<endl;
		return ;
	}
	for(int i=l[x];i<=r[x];i++) {
		cout<<i<<' ';
		num[x]=i;
		dfs(x+1,sum+i);
	}
}

signed main() {
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>T;
	while(T--) {
		cin>>n>>s;
		memset(num,0,sizeof(num));
		mx=0;
		for(int i=1;i<=n;i++) {
			cin>>l[i]>>r[i];
		}
		if(n==1) {
			cout<<s<<endl;
			continue;
		}
		dfs(1,0);
		cout<<mx<<endl;
	}
	return 0;
}
