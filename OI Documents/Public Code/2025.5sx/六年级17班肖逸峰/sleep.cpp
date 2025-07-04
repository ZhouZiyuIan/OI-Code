#include<bits/stdc++.h>
using namespace std;
int n, t, a[1000005], sum;
int main() {
	freopen("sleep.in", "r", stdin);
	freopen("sleep.out", "w", stdout); 
	cin >> n >> t;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	t %= sum;
	for (int i = 1; i <= n; i++) {
		if (t < a[i]) {
			if (t == 0) cout << i - 1 << "\n0";
			else cout << i << "\n" << a[i] - t;
			return 0;
		}
		t -= a[i];
	}
	cout << n << " " << a[n] - t;
} 
