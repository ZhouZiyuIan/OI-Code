#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
int n,y,x[1005],tmp,ans;
map<int,bool>vis;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			tmp=abs(x[i]-x[j]);
			if(!vis[tmp]){
				vis[tmp]=1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
