#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
set<int>S;
char s[N];
bool o[N];
map<char,int>t;
struct node{
	int a;
	char b; 
}vis[N];
int k,ans,cnt;
bool cmp(node x,node y){
	if(x.a>y.a)return x.b>y.b;
	return x.a<y.a;
}
signed main(){
	freopen("goof.in","r",stdin);
	freopen("goof.out","w",stdout);
	scanf("%s%lld",s+1,&k);
	int ls=strlen(s+1);
	if(ls<=k){
		puts("0");
		return 0;
	}
	for(int i=1;i<=ls;i++)t[s[i]]++;
	for(char i='a';i<='z';i++){
		vis[++cnt].a=t[i];
		vis[cnt].b=i;
	}
	sort(vis+1,vis+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		if(vis[i].a<k){
			k-=vis[i].a;
			for(int j=1;j<=ls;j++){
				if(s[j]==vis[i].b)o[j]=1;
			}
		}else if(vis[i].a>k){
			break;
		}
	}
	for(int i=1;i<=ls;i++){
		if(!o[i])S.insert(s[i]);
	}
	printf("%lld",S.size());
	puts("");
	for(int i=1;i<=ls;i++){
		if(!o[i])printf("%c",s[i]);
	}
}
