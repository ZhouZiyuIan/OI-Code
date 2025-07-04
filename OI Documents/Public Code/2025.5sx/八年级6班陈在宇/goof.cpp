#include<bits/stdc++.h>
using namespace std;
int n,k,t;
string s;
bool v[26];
struct node{
	int s,i;
}a[26];
bool cmp(node a,node b){
	return a.s<b.s;
}
int main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>s>>k;
	n=s.length(),s=" "+s;
	for(int i=0;i<26;i++)a[i].i=i;
	for(int i=1;i<=n;i++)a[s[i]-'a'].s++;
	sort(a,a+26,cmp);
	for(int i=0;i<26;i++){
		if(k>=a[i].s)k-=a[i].s,v[a[i].i]=1,t++;
		else break;
	}
	cout<<26-t<<'\n';
	for(int i=1;i<=n;i++)if(!v[s[i]-'a'])cout<<s[i];
}

