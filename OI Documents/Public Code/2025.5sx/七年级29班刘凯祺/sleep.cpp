#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;
ll n,k,a[1000001],sum;
signed main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;;i++){
		sum+=a[i];
		if(sum >= k){
			cout << i << endl << sum-k;
			break;
		}
		if(i >= n){
			cout << n << endl << 0;
			break; 
		}
	}
	return 0;
}
