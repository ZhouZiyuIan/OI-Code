#include<bits/stdc++.h>
using namespace std;
int n;
long long y;
long long a[100001];
map<long long,bool>t;
long long ans;
int main() {
    freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//cout<<a[1]<<" "<<a[2]<<a[n]<<endl;
	for(int i=1; i<=n; i++) {
		for(int j=i+1; j<=n; j++) {
			if(t[a[j]-a[i]]==0) {
				t[a[j]-a[i]]=1;
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}
