#include<bits/stdc++.h>
using namespace std;
long long n,t,a[100000001];
int main()
{
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		if(t-a[i]<=0){
			cout<<i+1<<endl;
			cout<<a[i]-t;
			return 0;
		}
		t-=a[i];
	}
	cout<<n-1;
	cout<<endl<<0;
}
