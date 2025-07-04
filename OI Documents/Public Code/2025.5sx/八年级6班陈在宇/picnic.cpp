#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1003;
int n,y,s;
ll x[N];
map<ll,bool>mp;
int main(){
	freopen("picnic.in","r",stdin);
	freopen("picnic.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>y;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		for(int j=1;j<i;j++){
			if(!mp[abs(x[i]-x[j])])mp[abs(x[i]-x[j])]=1,s++;
		}
	}
	cout<<s;
}

