#include<bits/stdc++.h>
#include<map>
using namespace std;
int n;
long long a[1005],ans,y;
map<long long,bool> vis;
int main() {
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	scanf("%d%lld",&n,&y);
	for(int i = 1;i <= n;i++) {
		scanf("%lld",&a[i]);
	}
	sort(a + 1,a + 1 + n);
	for(int i = 1;i <= n;i++) {
		for(int j = i + 1;j <= n;j++) {
			long long tmp = a[j] - a[i];
			if(vis[tmp] == 0 && tmp != 0) {
				vis[tmp] = 1;
				ans++;
			}
		}
	}
	printf("%lld",ans);
}
