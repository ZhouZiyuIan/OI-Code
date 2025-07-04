#include<bits/stdc++.h>
#define LL long long
struct st {
	int x,y;
} a[40];
bool cmp(st j,st k) {
	if(j.x>k.x) {
		return 1;
	}
	return 0;
}
LL f,k,len,vis[26];
char s[100009];
using namespace std;
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s;
	len=strlen(s);
	scanf("%lld",&k);
	for(int i=0; i<len; i++) {
		a[s[i]-'a'+1].x++;
	}
	sort(a+1,a+1+26,cmp);
	for(int i=26; i>=1; i--) {
		a[i].y=i;
		if(a[i].x<=k&&a[i].x!=0) {
			k-=a[i].x;
			a[i].x=0;
			vis[a[i].y]=1; 
		} else if(a[i].x!=0) {
			f++;
		}
	}
	printf("%lld\n",f);
	if(f==0) {
		return 0;
	}
	for(int i=0; i<len; i++) {
		if(vis[s[i]-'a'+1]==0) {
			cout<<s[i];
		}
	}
	return 0;
}

