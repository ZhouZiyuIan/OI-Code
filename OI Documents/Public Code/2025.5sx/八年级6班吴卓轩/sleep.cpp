#include<bits/stdc++.h>

#define ll long long
using namespace std;
const int N=1e5+5;

int n;
ll a[N],t,sum,k;

int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>t;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		sum+=a[i];
		if(sum>=t) {
			cout<<i<<endl<<sum-t;
			return 0;
		} 
	}
	sum=t%sum;
	for(int i=1;i<=n;i++) {
		k+=a[i];
		if(k>=sum) {
			cout<<i<<endl<<k-sum;
			break;
		}
	}
	return 0;
}
