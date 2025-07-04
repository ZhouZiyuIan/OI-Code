#include<bits/stdc++.h>
#define ll long long
#define cst const
#define endl '\n'
using namespace std;
int n,k,ans=26;
char s[100005];
bool vis[150];
struct node{
	char c;
	int cnt;
}a[150];
bool cmp(cst node&x,cst node&y){
	return x.cnt<y.cnt;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s+1>>k;
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		a[s[i]].c=s[i];
		a[s[i]].cnt++;
	}
	sort(a+'a',a+'z'+1,cmp);
	for(int i='a';i<='z';i++){
		if(!a[i].cnt){
			ans--;
			continue;
		}
		if(k>=a[i].cnt){
			ans--;
			k-=a[i].cnt;
			vis[a[i].c]=1;
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
		if(!vis[s[i]])
			cout<<s[i]; 
	return 0;
}
