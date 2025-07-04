#include<bits/stdc++.h>
using namespace std;
int n,k;
char s[100001];
int ans;
int a[30];
struct st {
	char x;
	int cnt;
} b[500];
bool cmp(st x,st y) {
	return x.cnt<y.cnt;
}
int c[500];
int t;
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;
	cin>>k;
	for(int i=0; i<strlen(s); i++) {
		if(a[s[i]-'a'+1]==0) {
			t++;
		}
		a[s[i]-'a'+1]++;
	}
	for(int i=1; i<=26; i++) {
		b[i].x=(char)'a'+i-1;
		b[i].cnt=a[i];
	}
	sort(b+1,b+26,cmp);
	for(int i=1; i<=26; i++) {
		if(b[i].cnt==0) {
			continue;
		}
		k-=b[i].cnt;
		if(k<0) {
			break;
		}
		ans++;
		c[b[i].x]=1;
	}
	cout<<t-ans<<endl;
	for(int i=0; i<strlen(s); i++) {
		if(!c[s[i]]) {
			cout<<s[i];
		}
	}
	return 0;
}
