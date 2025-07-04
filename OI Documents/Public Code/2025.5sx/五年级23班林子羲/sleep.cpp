#include<bits/stdc++.h>
#define ll long long
using namespace std; 
ll n;
ll t;
ll ans1;
ll ans2;
ll k = 0;
ll kk;
ll kkk;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("skeep.out","w",stdout);
	cin >> n >> t;
	ll a[n + 5];
	for (ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	if (k < t){
	   for (ll i = 1; i <= n; i++){
	       for (ll j = 1; j <= a[i]; j++){
        	   if (k == t){
        	      ans1 = i;
        	      ans2 = a[i] - (a[i] - j);
        	      cout << ans1 << endl << ans2;
        	      return 0;
			   }
			   k++;
			   kk = a[i] - (a[i] - j);
			   kkk = i;
		   }
	   }		
	   if (k == t){
	   	  cout << kkk << endl << kk;
	   }
	} 
	return 0;
}
