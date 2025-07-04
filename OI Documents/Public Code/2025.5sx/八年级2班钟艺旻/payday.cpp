#include<bits/stdc++.h>
using namespace std;
int t;
int n,s;
int l,r;
int sum;
int main() {
	freopen("payday.in","r",stdin);
	freopen("payday.out","w",stdout);
	cin>>t;
	while(t--) {
		cin>>n>>s;
		for(int i=1; i<=n; i++) {
			cin>>l>>r;
			sum+=l;
		}
		cout<<sum/n<<endl;
	}
	return 0;
}
