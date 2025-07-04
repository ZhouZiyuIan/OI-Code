#include<bits/stdc++.h>

#define int long long
using namespace std;

int n,x[1005],y;
set<double> s;

signed main() {
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	cin>>n>>y;
	for(int i=1;i<=n;i++)
		cin>>x[i];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(i==j) continue;
			double tmp=(double)((abs(x[i]-x[j])*y*1.0)/2.0);
//			cout<<tmp<<endl;
			s.insert(tmp);
		}
	}
	cout<<s.size();
	return 0;
}
