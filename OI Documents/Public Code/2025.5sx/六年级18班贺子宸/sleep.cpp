#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
ll n,t,x,s[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>x;
		s[i]=s[i-1]+x;
	}
	t%=s[n];
	for(int i=1;i<=n;i++){
		if(t<=s[i]){
			cout<<i<<endl<<s[i]-t;
			break;
		}
	}
	return 0;
}
