#include<bits/stdc++.h>
using namespace std;
int n;
long long t;
long long a[100001];
long long sum;
long long s;
int cnt;
int main() {
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		sum+=a[i];
	}
	s=t%sum;
	cnt=1;
	while(1) {
		s-=a[cnt];
		if(s<=0) {
			cout<<cnt<<endl;
			cout<<-s;
			return 0;
		}
		cnt++;
	}
	return 0;
}
//shisaijiayou
