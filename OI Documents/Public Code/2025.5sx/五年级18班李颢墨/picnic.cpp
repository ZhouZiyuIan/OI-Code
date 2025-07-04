#include<bits/stdc++.h>
using namespace std;
int n,y,x[1005],ans;
map<long long,int> vis;
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%d",&n,&y);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(!vis[abs(x[i]-x[j])*y]){
				ans++;
				vis[abs(x[i]-x[j])*y]=1;
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
