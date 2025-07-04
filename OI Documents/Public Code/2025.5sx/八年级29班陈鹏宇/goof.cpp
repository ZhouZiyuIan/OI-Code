#include<bits/stdc++.h>
using namespace std;
int k,m,n[30];
string s;
struct word {
	char a;
	int sum;
} v[30];
int c(char x) {
	return int(x-'a');
}
bool cmp(word x,word y) {
	return x.sum<y.sum;
}
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s>>k;
	for(int i=0; i<=25; i++) {
		v[i].a=char(i+'a');
		v[i].sum=0x3f3f3f3f;
	}
	for(int i=0; i<s.size(); i++) {
		if(v[c(s[i])].sum==0x3f3f3f3f) {
			v[c(s[i])].sum=0;
			m++;
		}
		v[c(s[i])].sum++;
	}

	sort(v,v+26,cmp);
	for(int i=0; i<=25; i++) {
		if(k>=v[i].sum) {
			k-=v[i].sum;
			v[i].sum=0;
			m--;
		}
	}
	for(int i=0; i<=25; i++)
		n[c(v[i].a)]=v[i].sum;

	cout<<m<<endl;
	for(int i=0; i<s.size(); i++) {
		if(n[c(s[i])]>0) {
			cout<<s[i];
			n[c(s[i])]--;
		}
	}
	return 0;
}
