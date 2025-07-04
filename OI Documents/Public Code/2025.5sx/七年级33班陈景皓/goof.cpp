#include<bits/stdc++.h>
#define rint register int
#define LL long long
using namespace std;
const int N=2e6+5,X=1e3+5;
string s;
int k,a[30],cnt;
struct _{
	int sum,id;
}t[30];
signed main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>s>>k;
	for(rint i=0;i<s.size();++i){
		int x=s[i]-'a';
		if(!a[x])++cnt;
		a[x]++;
		t[x].sum++;
		t[x].id=x;
	}
	sort(t,t+26,[](_ x,_ y){return x.sum<y.sum;});
	for(rint i=0;i<=25;++i){
		if(!t[i].sum)continue;
		if(t[i].sum>k)continue;
		cnt--;
		k-=t[i].sum;
		a[t[i].id]=0;
	}
	cout<<cnt<<'\n';
	for(rint i=0;i<s.size();++i){
		int x=s[i]-'a';
		if(a[x])cout<<s[i];
	}
	return 0;
}

