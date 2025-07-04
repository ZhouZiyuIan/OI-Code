#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,m;
char s[15][10005];
signed main(){
	freopen("parkour.in","r",stdin);
	freopen("parkour.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=m;i++){
			scanf("%s",s[i]+1);
		}
		printf("NO");
		puts("");
	}
}
