#include<bits/stdc++.h>
using namespace std;
int n,x[100005];
long long t,sum;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1; i<=n; i++) {
		cin>>x[i];
		sum+=x[i];
	}
	t%=sum;
	for(int i=1; i<=n; i++) {
		if(t>x[i])t-=x[i];
		else {
			cout<<i<<endl<<x[i]-t;
			return 0;
		}
	}
	return 0;
}
