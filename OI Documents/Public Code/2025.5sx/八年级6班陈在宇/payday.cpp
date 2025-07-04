#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+3;
int t,n,l,r;
ll s;
struct node{
	int l,r;
}a[N];
bool cmp(node a,node b){
	return a.l>b.l;
}
bool chk(int x){
	ll t=s;
	int l=0;
	for(int i=1;i<=n;i++){
		if(a[i].r<x)continue;
		t-=max(0,x-a[i].l);
		if(t<0)break;
		l++;
	}
	return l>n/2;
}
int main(){
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s;
		for(int i=1;i<=n;i++){
			cin>>a[i].l>>a[i].r;
			s-=a[i].l;
		}
		sort(a+1,a+n+1,cmp);
		l=1,r=1e9;
		while(l<r){
			int m=(l+r)/2+1;
			if(chk(m))l=m;
			else r=m-1;
		}
		cout<<l<<'\n';
	}
}

