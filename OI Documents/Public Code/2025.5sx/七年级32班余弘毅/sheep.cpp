#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2005],vis[2005],cnt,n;
inline void dfs(int x){
	if(x>n) return cnt++,void();
	if(a[x]!=-1) return dfs(x+1),void();
	for(int i=1;i<=n;i++){
		if(i!=x&&!vis[i]){
			vis[i]=1;
			dfs(x+1);
			vis[i]=0;
		}
	}
}
signed main(){
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=-1) vis[a[i]]=1;
	}
	dfs(1);
	cout<<cnt;
	return 0;
} 
