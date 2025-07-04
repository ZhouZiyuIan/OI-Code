#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
cst int N=200005;
ll t,n,s,l,r,mid,ans;
struct node{
	int l,r;
}a[N];
bool cmp(cst node&x,cst node&y){
	return x.l==y.l?x.r<y.r:x.l<y.l;
}
bool chk(cst int&x){
	ll pos=0,tot=x;
	for(int i=1;i<=n;i++){
		if(a[i].l<=x&&a[i].r>=x){
			pos=i;
			break;
		}
	}
	if(!pos)return 0;
	return 1;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>s;
		l=1;r=n;
		for(int i=1;i<=n;i++)
			cin>>a[i].l>>a[i].r;
		sort(a+1,a+1+n,cmp);
		while(l<r){
			mid=l+((r-l)>>1);
			if(chk(mid)){
				l=mid+1;
				ans=mid;
			}else
				r=mid;
		}
		cout<<ans<<endl;
	}
	return 0;
}
