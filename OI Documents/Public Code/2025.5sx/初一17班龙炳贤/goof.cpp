#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;
int k,len,tot = 0,ans;
char s[100005],a[100005];
map<char,int> vis;
bool cmp(char x,char y) {
	return vis[x] < vis[y];
}
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;
	cin>>k;
	len = strlen(s);
	for(int i = 0;i < len;i++) {
		if(vis[s[i]] == 0) {
			a[++tot] = s[i];
			ans++;
		}
		vis[s[i]]++;
	}
	sort(a + 1,a + 1 + tot,cmp);
	int tmp = 1;
	while(vis[a[tmp]] <= k && tmp <= tot) {
		k -= vis[a[tmp]];
		for(int i = 0;i < len;i++) {
			if(s[i] == a[tmp]) {
				s[i] = 0;
			}
		}
		tmp++;
		ans--;
	}
	cout<<ans<<endl;
	for(int i = 0;i < len;i++) {
		if(s[i] != 0) {
			cout<<s[i];
		}
	}
}
