#include<bits/stdc++.h>
using namespace std;
set<long long> tre;
int n,y,ans;
long long x[1005];
int main() {
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1; i<=n; i++)
		cin>>x[i];
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(tre.count(abs(x[j]-x[i]))==0) {
				ans++;
				tre.insert(abs(x[j]-x[i]));
			}
		}
	}
	cout<<ans;
	return 0;
}
