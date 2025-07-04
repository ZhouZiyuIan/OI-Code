#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
cst ll mod=1000000007;
ll n,x,cnt,ans=1;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("sheep.in","r",stdin);
	freopen("sheep.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>x;
		if(x==-1)
			cnt++;
	}
	for(ll i=1;i<cnt;i++)
		ans=(ans*i)%mod;
	cout<<ans;
	return 0;
}
