#include<bits/stdc++.h>
using namespace std;
char a[100000];
int k,g[27]= {},len,z=0;
int main() {
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s",a);
	len=strlen(a);
	for(int i=0; i<len; i++) {
		g[a[i]-96]++;
	}
	cin>>k;
	if(k>len) {
		cout<<0<<endl;
		return 0;
	}
	for(int i=26; i>=1; i--) {
		if(g[i]!=0) {
			if(k>=g[i]) {
				k-=g[i];
				g[i]=0;
			} else {
				break;
			}
		}
	}
	for(int i=1; i<27; i++) {
		if(g[i]!=0) {
			z++;
		}
	}
	cout<<z<<endl;
	for(int i=0; i<len; i++) {
		if(g[a[i]-96]!=0) {
			if(k>0) {
				k--;
			} else {
				cout<<a[i];
			}
		}
	}
	return 0;
}
/*ÑùÀý1
aaaaa
4
ÑùÀý2
abacaba
4
ÑùÀý3
abcdefgh
10
*/
