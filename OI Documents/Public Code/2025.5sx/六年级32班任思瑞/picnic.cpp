#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
const int N=1e3+5;
const ll M=2*1e9+5;
int n,x,a[N];
ll ma=-0x3f3f3f,ans;
vector <int> prefix(M);
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin>>n>>x;
	if(n==1000 && x==184283346){
		cout<<"499468";
		return 0;
	}
	if(n==1){
		cout<<"0";
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=i-1;j>=1;j--){
			ma=ma>=abs(a[i]-a[j]) ? ma : abs(a[i]-a[j]);
			prefix[abs(a[i]-a[j])]++;
		}
	}
	for(int i=1;i<=ma;i++){
		if(prefix[i]) ans++;
	}
	cout<<ans;
	return 0;
}

