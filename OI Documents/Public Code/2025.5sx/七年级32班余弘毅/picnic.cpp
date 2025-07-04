#include<bits/stdc++.h>
#define N 100005
#define int long long
using namespace std;
int x[N],n,cnt;
map<int,int>vis;
signed main(){	
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>x[0];
	for(int i=1;i<=n;i++) cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!vis[abs(x[i]-x[j])]&&x[i]!=x[j]) vis[abs(x[i]-x[j])]=1,cnt++;
		}
	}
	cout<<cnt;
	return 0;
} 
