#include<bits/stdc++.h>
#define N 10000005
#define int long long
using namespace std;
char s[N];
int n,cnt,op,vis[35];
inline int get(char c){return c-'a'+1;}
struct Node{
	int v,id;
	inline bool operator < (const Node &o) const{return v<o.v;}
}a[35];
signed main(){	
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	cin>>s+1>>op;
	n=strlen(s+1);cout<<n;
	for(int i=1;i<=n;i++) a[get(s[i])].v++,cnt+=(a[get(s[i])].v==1); 
	for(int i=1;i<=26;i++){
		a[i].id=i;
		if(!a[i].v) a[i].v=INT_MAX;
	}
	sort(a+1,a+27);
	for(int i=1;i<=26;i++){
		if(a[i].v<=op) op-=a[i].v,vis[a[i].id]=1,cnt--;
		else break;
	}
	cout<<cnt<<'\n';
	for(int i=1;i<=n;i++){
		if(!vis[get(s[i])]) cout<<s[i];
	} 
	return 0;
} 
