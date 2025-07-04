#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=1e9+7;
int n,a[N],vis[N],vis1[N],ans;
void dfs(int x) {
	if(x>n) {
		int flag=0;
		for(int i=1;i<=n;i++) {
			if(a[i]==i) {
				flag=1;
				break;
			}
		}
		if(flag==0) {
			ans++;
			ans%=mod;
		}
		return ;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]==1) {
			vis[i]=0;
			for(int j=1;j<=n;j++) {
				if(vis1[i]==0) {
					vis1[i]=1;
					a[i]=j;
					dfs(x+1);
					a[i]=0;
					vis1[i]=0;
				}
			}
			vis[i]=1;
		}
	}
}
int main() {
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==-1) vis[i]=1;
		else vis1[a[i]]=1;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
