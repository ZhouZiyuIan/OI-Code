#include<bits/stdc++.h>
#include<set>
using namespace std;
int t,n,s;
long long l[200005],r[200005],ans;
bool fun(long long x) {
	int mn = 0,mx = 0;
	for(int i = 1;i <= n;i++) {
		if(r[i] < x) {
			mn++;
			a.insert(l[i]);
		}
		if(l[i] > x) {
			mx++;
			a.insert(l[i]);
		}
		if(l[i] <= x && x <= r[i]) {
			if(mn <= mx) {
				mn++;
				a.insert(l[i]);
			} else {
				mx++;
				a.insert(l[i]);
			}
		}
	}
//	if() {
//		return 1;
//	} else {
//		return 0;
//	}
}
long long erfen(long long h,long long t) {
	while(h <= t) {
		long long mid = (h + t) / 2;
		if(fun(mid)) {
			h = mid + 1;
			ans = mid;
		} else {
			t = mid - 1;
		}
	}
}
int main() {
	set<long long> a;
	cout<<a.count(1);
	cin>>t;
	for(int i = 1;i <= t;i++) {
		cin>>n>>s;
		long long ml = 0,mr = 0;
		for(int j = 1;j <= n;j++) {
			cin>>l[j]>>r[j];
			ml = max(ml,l[j]);
			mr = max(mr,r[j]);
		}
		ans = 0;
		erfen(ml,mr);
		cout<<ans<<endl;
	}
}
