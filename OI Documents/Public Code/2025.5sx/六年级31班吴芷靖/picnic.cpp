#include<bits/stdc++.h>
using namespace std;
int n,y,w=0,k,c,z=0;
long long a[1000];
double b[1000];
int panduan(double x) {
	for(int i=0; i<w; i++) {
		if(x==b[i]) {
			return 1;
		}
	}
	return 0;
}
int main() {
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>y;
	if(n<2) {
		cout<<0;
		return 0;
	}
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=0; i<n; i++) {
		for(long long j=i+1; j<n; j++) {
			b[w]=0.5*(a[j]-a[i])*y;
			w++;
		}
	}
	sort(b,b+w);
	z=w;
	for(long long i=0; i<w; i++) {
		if(b[i]==b[i-1]&&i!=0) {
			z--;
		}
	}
	cout<<z;
	return 0;
}
/*ÑùÀý1
4 1
1 2 4 5
ÑùÀý2
1 9
50
ÑùÀý3
6 7
1 2 4 8 16 32
*/

