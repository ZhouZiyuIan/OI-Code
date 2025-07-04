#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2*1e5+5;
ll n,s;
struct Node {
	ll l;
	ll r;
}a[N];
bool cmp(Node x,Node y) {
	return x.r < y.l ;
}
int main() {
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	int T;
	cin>>T;
	while(T--) {
		cin>>n>>s;
		for(int i=1;i<=n;i++) {
			cin>>a[i].l>>a[i].r;
		}
		sort(a+1,a+n+1,cmp);
		cout<<s<<endl;
	}
	return 0;
}
