#include<bits/stdc++.h>
using namespace std;
long long n,t,r,z=0;
long long a[100000];
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(long long i=1; i<=n; i++) {
		cin>>a[i];
		z+=a[i];
	}
	r=t%z;
	z=0;
	for(long long i=1; i<=n; i++) {
		if(z+a[i]>=r) {
			cout<<i<<endl;
			cout<<a[i]-r+z;
			return 0;
		}
		z+=a[i];
	}
	return 0;
}
/*ÑùÀý1
3 4
1
2
3
ÑùÀý2
3 9
1
2
3
*/
