#include<iostream>
#include<vector>

#define ll long long
using namespace std;

int n,a[2005],flag[2005],ans,vis[2005];
vector<int> num[2005];

void dfs(int x) {
	if(x>n) {
		ans++;
		ans%=1000000007;
		return ;
	}
	if(flag[x]) {
		for(auto i:num[x]) {
			if(vis[i]) continue;
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
	else {
		dfs(x+1);
	}
}

int main() {
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]==-1) {
			flag[i]=1;
		}
	}
	for(int i=1;i<=n;i++) {
		if(flag[i]) {
			for(int j=1;j<=n;j++) {
				if(i==j) continue;
				if(flag[j]) {
					num[i].push_back(j);
				}
			}
		}
	}
	dfs(1);
	cout<<ans;
	return 0;
}
