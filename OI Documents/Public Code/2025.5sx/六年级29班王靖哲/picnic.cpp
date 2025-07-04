#include<bits/stdc++.h>
using namespace std;
long long ans,n,y,x[1100];
double ss[500000];
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%lld%lld",&n,&y);
	for(int i=1;i<=n;i++){
		scanf("%lld",&x[i]);
	}for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i)continue;
			double s=((max(x[j],x[i])-min(x[j],x[i]))*y*1.0)/2;
			for(int t=1;;t++){
				if(ss[t]==s)break;
				if(ss[t]==0){
					ss[t]=s;
					ans++;
					break;
				}
			}
		}
	}printf("%lld",ans);
}

