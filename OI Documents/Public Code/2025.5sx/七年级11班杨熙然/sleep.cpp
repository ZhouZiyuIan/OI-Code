#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	ll n,t;
	cin >> n >> t;
	ll a[n+1]={},a1=0;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		a1 += a[i];
	}
	t %= a1;
	for(int i = 1;i <= n;i++){
		t -= a[i];
		if(t <= 0){
			cout << i << endl << abs(t);
			return 0;
		}
	}
	return 0;
}
