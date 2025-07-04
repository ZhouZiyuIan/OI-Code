#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
char s[N];
int k,len,vis[30];
struct Node {
	int num;
	char k;
}a[30];
bool cmp(Node x,Node y) {
	return x.num < y.num;
}
bool cmp1(Node x,Node y) {
	return x.k < y.k;
}
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",s+1);
	cin>>k;
	len=strlen(s+1);
	for(int i=1;i<=26;i++) a[i].k='`'+i;
	for(int i=1;i<=len;i++) {
		a[s[i]-'a'+1].num++;
	}
	sort(a+1,a+27,cmp);
	for(int i=1;i<=26;i++) {
		if(k-a[i].num>=0) {
			k-=a[i].num;
			a[i].num=0;
		}
		else {
			a[i].num-=k;
			k=0;
			break;
		}
	}
	sort(a+1,a+27,cmp1);
	int ans=0;
	for(int i=1;i<=26;i++) {
		if(a[i].num>0) ans++;
	}
	cout<<ans<<"\n";
	for(int i=1;i<=len;i++) {
		int k=s[i]-'a'+1;
		if(vis[k]+1<=a[k].num) {
			vis[k]++;
			cout<<s[i];
		}
	}
	return 0;
}
