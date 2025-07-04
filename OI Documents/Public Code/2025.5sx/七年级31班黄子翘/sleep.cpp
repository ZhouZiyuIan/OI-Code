#include<bits/stdc++.h>
using namespace std;
int n,t,a[100010],s1,s2;
unsigned long long b,c,d;
int main(){
	freopen("sleep.in","r",stdin);
	freopen("sleep.out","w",stdout);
	cin>>n>>t;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b=b+a[i];
	}
	c=t%b;
	while(d<c){
		s1++;
		d=d+a[s1];
	}
	s2=d-c;
	cout<<s1<<endl;
	cout<<s2<<endl;
	return 0;
}
