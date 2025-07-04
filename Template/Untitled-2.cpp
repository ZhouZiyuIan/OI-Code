#include<bits/stdc++.h>
using namespace std;
int n,k,j=1,cnt=1,t[256];
char x[50000010];
long long ans=1;
int main() {
	cin>>n>>k>>x+1;
	for(int i=1; i<=n; i++) {
		t[x[i]]++;
		while(j<=i) {
			if(t[x[i]]>k) {
				t[x[j++]]--; 
			}
			else {
				break;
			}
		}
		ans+=i-j+1;
	}
	cout<<ans;
	return 0;
}