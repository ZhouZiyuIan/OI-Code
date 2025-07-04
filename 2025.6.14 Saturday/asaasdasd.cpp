#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
cst int N=100005;
int t,n,m,a,sum,ans;
multiset<int>s;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("car123123.in","r",stdin);
	freopen("car.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n>>m;
		s.clear();
		for(int i=1;i<=n;i++){
			cin>>a;
			sum=0;ans=i-1;
			for(cst auto&j:s){
				sum+=j;
				if(sum>m-a)
					break;
				ans--;
			}
			s.insert(a);
			cout<<ans<<' ';
		}
		cout<<endl;
	}
	return 0;
}
