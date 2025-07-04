#include<bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int N=1e5+5;

string s,ss;
int n,k,sum,ans;
pair<char,int> x[27];
map<char,int> mp,mp1;

int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>s>>k;
	n=s.size();
	if(k>=n) return cout<<0<<endl,0;
	for(int i=0;i<n;i++) {
		int xx=s[i]-'a'+1;
		x[xx].fi=s[i];
		x[xx].se++;
	}
	sort(x+1,x+26+1,[](pii x,pii y) {return x.se<y.se;});
	for(int i=1;i<=26;i++) {
		if(!x[i].se) continue;
		sum+=x[i].se;
		if(sum>k) {
			break;
		}
		mp[x[i].fi]++;
	}
	for(int i=0;i<n;i++) {
		if(mp[s[i]]) continue;
		ss+=s[i];
	}
	for(int i=0;i<ss.size();i++) {
		if(!mp1[ss[i]]) ans++;
		mp1[ss[i]]++;
	}
	cout<<ans<<endl<<ss;
	return 0;
}
