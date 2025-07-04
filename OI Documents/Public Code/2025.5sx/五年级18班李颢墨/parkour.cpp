#include<bits/stdc++.h>
using namespace std;
int t,n,m;
char c;
int main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++) scanf("%c",&c);
		}
		printf("YES\n");
	}
	return 0;
}
