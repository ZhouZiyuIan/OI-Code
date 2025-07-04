#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,y,a[100001],sum;
bool vis[10000001];
int f(int x){
	if(x>=0) return x;
	else return -x;
}
signed main(){
	freopen("simpleB.in","r",stdin);
	freopen("simpleB.out","w",stdout);
	cin >> n >> y;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int t=f(a[i]-a[j]);
			if(!vis[t]){
				vis[t]=true;
				sum++;
			}
		}
	}
	cout<<sum;
	return 0;
}
